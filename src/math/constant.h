/**
 *    > Author:   whpointz
 *    > Mail:     506273980@qq.com
 *    > Github:   https://www.github.com/whpointz
 *    > Description: 一些会用到的数学常量
 *
 *    > Created Time: 2017/05/09 23:41:37
**/

#ifndef _CONSTANT_H_
#define _CONSTANT_H_

#include <math.h>
#include <limits>

namespace OpRt
{

	const double PI = 3.141592653589793238;
	const double PI_INV = 1.0 / PI;
	const double DOU_PI = 2.0 * PI;
	const double DOU_PI_INV = 1.0 / DOU_PI;
	const double kInfinity = std::numeric_limits<double>::max();
	const double kEpsilon = 1e-4;
	const double E = 2.718281828459045;

	enum Axis { Xaxis = 0, Yaxis, Zaxis };

	inline double radian(double angle) {
		return angle * (PI / 180.0);
	}

	inline double rradian(double angle) {
		return angle * (180.0 / PI);
	}



} // namespace OpRt

#endif /* _CONSTANT_H_ */