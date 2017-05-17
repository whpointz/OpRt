/**
 *    > Author:   whpointz
 *    > Mail:     506273980@qq.com
 *    > Github:   https://www.github.com/whpointz
 *    > Description:
 *
 *    > Created Time: 2017/05/06 15:44:20
**/

#ifndef _RAY_H_
#define _RAY_H_

#include "../object/sphere.h"
#include "../core/light.h"
#include <vector>

namespace OpRt {

class  Ray
{
	public:

		Ray(const Point3d &ori, const Vector3d &dir) :ori_(ori), dir_(dir) { }

		void setOrigin(const Point3d &ori){ ori_ = ori; }
		void setDirection(const Vector3d &dir){ dir_ = dir; }
		
		const Point3d & origin() const { return ori_; }
		const Vector3d & direction() const { return dir_; }

		Color trace(const std::vector<Sphere* > &, int,  const std::vector<Light* > &);

		//Í¨¹ý
		void ComputeDirection(const int &width, const int &height, const int &x, const int &y, const double &angle){
			dir_.x_ = (2 * ((x + 0, 5) / width) - 1) * angle;
			dir_.y_ = (1 - 2 * ((y + 0.5) / height)) * angle;
			dir_.z_ = -1;
			normalize(dir_);
		}

	private:

		Point3d ori_;
		Vector3d dir_;

		friend std::ostream& operator << (std::ostream &os, const Ray &ray){
			return os << "ori: " << ray.ori_ << "dir:" << ray.dir_;
		}

		Sphere* _findHitObject(const std::vector<Sphere* > &, double &);

};

}// namespace OpRt


#endif /* _RAY_H_ */