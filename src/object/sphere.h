/**
 *    > Author:   whpointz
 *    > Mail:     506273980@qq.com
 *    > Github:   https://www.github.com/whpointz
 *    > Description:
 *
 *    > Created Time: 2017/05/06 15:42:04
**/

#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "../core/material.h"
#include "../math/vector.h"
#include "../math/constant.h"


namespace OpRt{

class Sphere
{
	public:
		
		Sphere(const double &radius, 
			  const Point3d &center, 
			  const Point3d &emission, 
			  const Point3d &color, 
			  const  Type &refl) 
			  :center_(center), radius_(radius), radius2_(radius * radius), inv2radius_(1.0 / (2 * radius)), emission_(emission), color_(color), refl_(refl) {  };
		
		//返回光源到球体的距离 值为-1说明光线和球体不相交  
		double  intersect(const Vector3d &origin, const Vector3d direction)const;

		std::ostream& print(std::ostream &os) {
			return os << "sphere\n center: " << center_ << "radius: " << radius_ << std::endl;
		}


	private:

		Point3d center_;
		Point3d emission_;
		Point3d color_;
		Type refl_;
		double radius_;
		double radius2_;
		double inv2radius_;


};


} //namespace OpRt



#endif /* _SPHERE_H_ */