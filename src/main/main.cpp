/**
 *    > Author:   whpointz
 *    > Mail:     506273980@qq.com
 *    > Github:   https://www.github.com/whpointz
 *    > Description:
 *
 *    > Created Time: 2017/05/04 21:04:32
**/

#include <stdio.h>
#include <iostream>
#include "../math/vector.h"
#include "../math/ray.h"

int main(){
	
	using namespace OpRt;

	Vector2d v1(1);
	Vector2d v2(2,3);


	printf("%d\n",v1==v2);
	std::cout << v1 << std::endl;
	std::cout << v1[0] << std::endl;
	std::cout << cross(v1, v2) << std::endl;
	std::cout << normalize(v1) << std::endl;
	std::cout << mul(v1, v2) << std::endl;
	std::cout << dot(v1, v2) << std::endl;




	printf("hello world!\n");

	Vector3d v3(1,2,3);
	Vector3d v4(4,4,6);
	printf("%d\n", v3 == v4);
	std::cout << v3 << std::endl;
	std::cout << v3[0] << std::endl;
	std::cout << cross(v3, v4) << std::endl;
	std::cout << normalize(v3) << std::endl;
	std::cout << mul(v3,v4) << std::endl;
	std::cout << dot(v3, v4) << std::endl;



	printf("hello world!\n");


	Ray ray(v3, v4);
	std::cout << ray << std::endl;

}



