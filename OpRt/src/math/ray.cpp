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
			double distance = spheres[i]->intersect(ori_, dir_);//�������i����֮��ľ���
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

		//���û�������ཻ
		if (!hitObject) return Color(0);

		//�ཻ��
		Vector3d hitPos = ori_ + dir_ * near;//dir_Ϊ��������

		//�ཻ��ķ�����
		Vector3d hitNormal = hitObject->center() - hitPos;
		normalize(hitNormal);

		bool into = true;
		// ��������������ߵķ�����ͬ��������ȡ��
		if (dot(dir_, hitNormal) > 0) hitNormal = -hitNormal,into = false;
		
		Color color(0.0);
		Type material = hitObject->refl();
		//������
		if (material == DIFF)
		{
			Vector3d newHitPos = hitPos + hitNormal*kEpsilon;

			//�жϷ�������(from cam )�Ƿ�����Ӱ�ڣ����Դ�йأ�
			for (int i = 0; i < lights.size(); i++)
			{
				bool flag = true;
				//�ƹ�i �������� �ķ�����ߵķ���
				Vector3d lightDir;
				double intensity = lights[i]->illuminate(hitPos, lightDir);
				double dissp;
				for (int j = 0; j < spheres.size(); j++)
				{
					//�ж� ��i����Դ�ķ������ �� ��j�����ཻ �Ƿ��ཻ�����ཻ��flagΪfalse
					dissp = spheres[j]->intersect(newHitPos, lightDir);
					if (dissp>0.0){
						flag = false;
						break;
					}
				}

				//�� ��i����Դ�ķ������ �� ���е��� �����ཻ,������������ɫ
				//����Ƿ�����������Ӱ��
				if (flag) color += (intensity*std::max(0.0, dot(hitNormal, lightDir))) * hitObject->surfaceColor();
				//color = hitObject->surfaceColor();
			}
		}
		else if (++depth < 3)
		{
			//�������ߣ�from camera���ķ���
			Vector3d reflDir = dir_ - 2 * dot(hitNormal, dir_) *hitNormal;
			normalize(reflDir);
			//���淴��
			if (material == SPEC) 
				color = Ray(hitPos, reflDir).trace(spheres, depth, lights);

			//��������� REFR
			else
			{
				double cosi = -dot(dir_, hitNormal);
				double eta = into ? 1.0 / 1.1 : 1.1;
				double fresnelEffect = pow(1 - cosi, 3)*0.9 + 0.1;//�����ЧӦ������
				double k = 1 - eta*eta*(1 - cosi*cosi);

				//�������ߣ�from camera���ķ���
				Vector3d refrDir = dir_ * eta + hitNormal*(eta * cosi - sqrt(k));
				normalize(refrDir);

				//һ���ַ��� һ��������
				color = Ray(hitPos + hitNormal * kEpsilon, reflDir).trace(spheres, depth, lights) * fresnelEffect +
					    Ray(hitPos - hitNormal * kEpsilon, refrDir).trace(spheres, depth, lights) *(1 - fresnelEffect);
			}
		}

		return color;
	}


} // namespace OpRt
