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

	void Sphere::computeBox(std::vector<double> &near, std::vector<double> &far, const Vector3d *normal) const{
		for (size_t i = 0, end = near.size(); i != end; ++i){
			double p = proj(center_,normal[i]);
			double n = p - radius_;
			double f = p + radius_;
			if (n < near[i]) near[i] = n;
			if (f > far[i]) far[i] = f;
		}
	}

	bool Sphere::hit(const Ray &ray, const double &distance) const{
		Vector3d l = center_ - ray.origin();
		double s = dot(l, ray.direction());
		double l2 = l.length2();

		if (s<0 && l2 > radius2_)
			return false;

		double q2 = l2 - s*s;
		if (q2 > radius2_)
			return false;

		double q = std::sqrt(radius2_ - q2);
		double dis = l2 > radius2_ ? (s - q) : (s + q);

		if (dis < distance) return true;
		return false;
	}





} // OpRt