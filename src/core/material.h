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


namespace OpRt
{

enum Type { DIFF, SPEC, REFR }; //反射的类型

class Material
{
	public:
		
		Material(Type type) : type_(type) {}
		Type type() const { return type_; }

		virtual ~Material() {}
	
	protected:
		Type type_;

};


} // namespace OpRt 

#endif /* _MATERIAL_H_ */