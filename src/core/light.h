/**
 *    > Author:   whpointz
 *    > Mail:     506273980@qq.com
 *    > Github:   https://www.github.com/whpointz
 *    > Description:
 *
 *    > Created Time: 2017/05/17 21:15:34
**/

#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "../math/vector.h"
#include "../math/constant.h"

namespace OpRt
{


class Light
{
	public:

		virtual double illuminate(const Vector3d &,Vector3d &) const = 0;
		virtual ~Light();

	private:

};


class PointLight : public Light
{
	public:
	
		PointLight(const Vector3d &origin, const double intensity = 1.0) :origin_(origin), intensity_(intensity) { }
		
		//通过 物体所在位置（pos） 来计算出  这个位置的光照强度
		double illuminate(const Vector3d &pos, Vector3d &dir) const override{
			dir = origin_ - pos;
			double r2 = dir.length() / (4 * PI);
			if (r2 < 1.0) r2 = 1.0;
			normalize(dir);
			return intensity_ / r2; 
		}

		~PointLight() {}

	private:
		Vector3d origin_; //点光源的位置
		double intensity_; //光照强度

};

class DirectionLight : public Light
{
	public:
		DirectionLight(const Vector3d &direction, const double intensity = 1.0) :direction_(direction), intensity_(intensity){ normalize(direction_); };

		double illuminate(const Vector3d &pos, Vector3d &dir) const override{
			dir = -direction_;
			return intensity_;
		}
		~DirectionLight();
	
	private:
		Vector3d direction_;
		double intensity_;

};


} // namespace OpRt

#endif /* _LIGHT_H_ */