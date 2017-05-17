/**
 *    > Author:   whpointz
 *    > Mail:     506273980@qq.com
 *    > Github:   https://www.github.com/whpointz
 *    > Description:
 *
 *    > Created Time: 2017/05/07 22:31:46
**/
#include "sphere.h"

namespace OpRt
{
	double Sphere::intersect(const Vector3d &origin,const Vector3d direction)const{
		Vector3d OriToCenter = center_ - origin;//�� ���ߵ���� �� ���� ������
		
		double Len = dot(OriToCenter, direction);// ���ߵ���㵽���ĵ����� �� ���ߵķ��� �ϵ�ͶӰ���� ��Ĭ�Ϲ��ߵķ�����һ����λ������

		if (Len < 0) return -1.0;//�������෴������ߺ����ཻ

		double CenterToRay2 = OriToCenter.length2() - Len*Len;//���ĵ����ߵľ���

		if (CenterToRay2 > radius2_) return -1.0;//�����ĵ����ߵľ��������İ뾶������ߺ����ཻ
		
		double distance = std::sqrt(radius2_ - CenterToRay2); //disΪ���������ڵľ���

		return Len - distance;//ͶӰ����-���������ڵľ��� = ��Դ�������ĳ���
	}

} // OpRt