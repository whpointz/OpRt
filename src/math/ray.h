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

#include "vector.h"

namespace OpRt {

class  Ray
{
	public:

		Ray(const Point3d &ori, const Vector3d &dir) :ori_(ori), dir_(dir) { }

		void SetOrigin(const Point3d &ori){ ori_ = ori; }
		void SetDirection(const Vector3d &dir){ dir_ = dir; }
		
		const Point3d & origin() const { return ori_; }
		const Vector3d & direction() const { return dir_; }

	private:

		Point3d ori_;
		Vector3d dir_;

		friend std::ostream& operator << (std::ostream &os, const Ray &ray){
			return os << "ori: " << ray.ori_ << "dir:" << ray.dir_;
		}

};

}// namespace OpRt


#endif /* _RAY_H_ */