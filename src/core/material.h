/**
 *    > Author:   whpointz
 *    > Mail:     506273980@qq.com
 *    > Github:   https://www.github.com/whpointz
 *    > Description:
 *
 *    > Created Time: 2017/05/09 23:02:01
**/

#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "../math/vector.h"

namespace OpRt
{

class Material
{
	public:
		enum Type {DIFF, SPEC, REFR};
		Material(Type type) : type_(type) {}
		Type type() const { return type_; }

		virtual ~Material() {}
	
	protected:
		Type type_;

};


} // namespace OpRt 

#endif /* _MATERIAL_H_ */