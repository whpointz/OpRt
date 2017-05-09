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

#include "../core/object.h"
#include "../core/material.h"

namespace OpRt{

class Sphere : public Object
{
	public:
		
		Sphere(const double  radius, const Point3d &center, const Point3d &emission, const Point3d &color, const  Material::Type &refl) :center_(center), radius_(radius), radius2_(radius * radius), inv2radius_(1.0 / (2 * radius)),emission_(emission),color_(color),refl_(refl) {  }
		
		//do this after 99 ray
		//void computeBox(std::vector<double> &near, std::vector<double> &far, const Vector3d *normal) const override; //const为常量性 在基类中也有const

		double  intersect(const Ray &r) const override;

		//do this after 99 ray
		//bool hit(const Ray &ray, const double &distance) const override;

		std::ostream& print(std::ostream &os) const override{
			return os << "sphere\n center: " << center_ << "radius: " << radius_ << std::endl;
		}


	private:

		Point3d center_;
		Point3d emission_;
		Point3d color_;
		Material::Type refl_;
		double radius_;
		double radius2_;
		double inv2radius_;


};


} //namespace OpRt



#endif /* _SPHERE_H_ */