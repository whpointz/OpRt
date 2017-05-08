/**
 *    > Author:   whpointz
 *    > Mail:     506273980@qq.com
 *    > Github:   https://www.github.com/whpointz
 *    > Description: Object为每个object对象的基类，其中定义了相交intersect 碰撞hit 以及计算包围盒 computeBox 
 *
 *    > Created Time: 2017/05/07 22:36:53
**/

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <vector>

#include "../math/ray.h"
namespace OpRt{

class Object
{
	public:

		Object() = default;

		virtual double intersect(const Ray &ray) const = 0;
		virtual bool hit(const Ray &ray,const double &distance) const{ return false; }
		virtual void computeBox(std::vector<double> &, std::vector<double> &, const Vector3d *) const{
			std::cerr << "virtual function called in Object :( \n";
			exit(-1);
		}

		virtual std::ostream& print(std::ostream &) const = 0;

		friend std::ostream& operator<<(std::ostream &os, const Object *obj){
			obj->print(os);
			return os;
		}

		virtual ~Object() {};

};



}// namespace OpRt

#endif /* _OBJECT_H_ */