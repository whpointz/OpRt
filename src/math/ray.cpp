/**
 *    > Author:   whpointz
 *    > Mail:     506273980@qq.com
 *    > Github:   https://www.github.com/whpointz
 *    > Description:
 *
 *    > Created Time: 2017/05/07 22:31:28
**/

#include "ray.h"

namespace OpRt
{


	Sphere* Ray::_findHitObject(const std::vector<Sphere *> &spheres, double &near){
		Sphere* hitObject = nullptr;
		for (int i = 0; i != spheres.size(); i++){
			double distance = spheres[i]->intersect(ori_, dir_);//射线与第i个球之间的距离
			if (distance > 0.0 && distance < near){
				near = distance;
				hitObject = spheres[i];
			}
		}
		return hitObject;
	}


	Color Ray::trace(const std::vector<Sphere *> &spheres, int depth, const std::vector<Light *> &lights){
		double near = DOUBLE_MAX;
		Sphere* hitObject = _findHitObject(spheres, near);

		//如果没有物体相交
		if (!hitObject) return Color(0);

		//相交点
		Vector3d hitPos = ori_ + dir_ * near;//dir_为方向向量

		//相交点的法向量
		Vector3d hitNormal = hitObject->center() - hitPos;
		normalize(hitNormal);

		bool into = true;
		// 如果法向量与射线的方向相同，法向量取反
		if (dot(dir_, hitNormal) > 0) hitNormal = -hitNormal,into = false;
		
		Color color(0.0);
		Type material = hitObject->refl();
		//漫反射
		if (material == DIFF)
		{
			Vector3d newHitPos = hitPos + hitNormal*kEpsilon;

			//判断反射射线(from cam )是否处在阴影内（与光源有关）
			for (int i = 0; i < lights.size(); i++)
			{
				bool flag = true;
				//灯光i 在物体上 的反射光线的方向
				Vector3d lightDir;
				double intensity = lights[i]->illuminate(hitPos, lightDir);
				double dissp;
				for (int j = 0; j < spheres.size(); j++)
				{
					//判断 第i个光源的反射光线 与 第j个球相交 是否相交，若相交，flag为false
					dissp = spheres[j]->intersect(newHitPos, lightDir);
					if (dissp>0.0){
						flag = false;
						break;
					}
				}

				//若 第i个光源的反射光线 与 所有的球 都不相交,返回这个球的颜色
				//这就是反射视线在阴影中
				if (flag) color += (intensity*std::max(0.0, dot(hitNormal, lightDir))) * hitObject->surfaceColor();
				//color = hitObject->surfaceColor();
			}
		}
		else if (++depth < 3)
		{
			//反射射线（from camera）的方向
			Vector3d reflDir = dir_ - 2 * dot(hitNormal, dir_) *hitNormal;
			normalize(reflDir);
			//镜面反射
			if (material == SPEC) 
				color = Ray(hitPos, reflDir).trace(spheres, depth, lights);

			//反射和折射 REFR
			else
			{
				double cosi = -dot(dir_, hitNormal);
				double eta = into ? 1.0 / 1.1 : 1.1;
				double fresnelEffect = pow(1 - cosi, 3)*0.9 + 0.1;//菲尼尔效应折射率
				double k = 1 - eta*eta*(1 - cosi*cosi);

				//折射射线（from camera）的方向
				Vector3d refrDir = dir_ * eta + hitNormal*(eta * cosi - sqrt(k));
				normalize(refrDir);

				//一部分反射 一部分折射
				color = Ray(hitPos + hitNormal * kEpsilon, reflDir).trace(spheres, depth, lights) * fresnelEffect +
					    Ray(hitPos - hitNormal * kEpsilon, refrDir).trace(spheres, depth, lights) *(1 - fresnelEffect);
			}
		}

		return color;
	}


} // namespace OpRt
