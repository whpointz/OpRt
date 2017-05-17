/**
 *    > Author:   whpointz
 *    > Mail:     506273980@qq.com
 *    > Github:   https://www.github.com/whpointz
 *    > Description:
 *
 *    > Created Time: 2017/05/07 22:31:46
**/
#include "sphere.h"

namespace OpRt
{
	double Sphere::intersect(const Vector3d &origin,const Vector3d direction)const{
		Vector3d OriToCenter = center_ - origin;//从 光线的起点 到 球心 的向量
		
		double Len = dot(OriToCenter, direction);// 光线的起点到球心的向量 在 光线的方向 上的投影长度 （默认光线的方向是一个单位向量）

		if (Len < 0) return -1.0;//若方向相反，则光线和球不相交

		double CenterToRay2 = OriToCenter.length2() - Len*Len;//球心到光线的距离

		if (CenterToRay2 > radius2_) return -1.0;//若球心到光线的距离大于球的半径，则光线和球不相交
		
		double distance = std::sqrt(radius2_ - CenterToRay2); //dis为光线在球内的距离

		return Len - distance;//投影长度-光线在球内的距离 = 光源到球表面的长度
	}

} // OpRt