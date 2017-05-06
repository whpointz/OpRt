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

	private:

		Point3d ori_;
		Vector3d dir_;

	};
}// namespace OpRt







#endif /* _RAY_H_ */