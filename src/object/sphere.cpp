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

	double Sphere::intersect(const Ray &r)const{
		Vector3d op = center_ - r.origin();
		double t, eps = 1e-4, b = dot(op, r.direction()), det = b*b - dot(op, op) + radius_*radius_;
		if (det < 0) return 0;
		else det = std::sqrt(det);
		return (t = b - det)>eps ? t : ((t = b + det)>eps ? t : 0);
	}

} // OpRt