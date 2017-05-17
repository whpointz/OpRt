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
#include "../object/sphere.h"
#include "../core/material.h"

int main(){
	
	using namespace OpRt;

	Sphere spheres[] =  //Scene: radius, position, emission, color, material
	{
		Sphere(1e5, Vector3d(1e5 + 1, 40.8, 81.6), Vector3d(), Vector3d(.75, .25, .25), DIFF),//Left
		Sphere(1e5, Vector3d(-1e5 + 99, 40.8, 81.6), Vector3d(), Vector3d(.25, .25, .75), DIFF),//Rght
		Sphere(1e5, Vector3d(50, 40.8, 1e5), Vector3d(), Vector3d(.75, .75, .75), DIFF),//Back
		Sphere(1e5, Vector3d(50, 40.8, -1e5 + 170), Vector3d(), Vector3d(), DIFF),//Frnt
		Sphere(1e5, Vector3d(50, 1e5, 81.6), Vector3d(), Vector3d(.75, .75, .75), DIFF),//Botm
		Sphere(1e5, Vector3d(50, -1e5 + 81.6, 81.6), Vector3d(), Vector3d(.75, .75, .75), DIFF),//Top
		Sphere(16.5, Vector3d(27, 16.5, 47), Vector3d(), Vector3d(1, 1, 1)*.999, SPEC),//Mirr
		Sphere(16.5, Vector3d(73, 16.5, 78), Vector3d(), Vector3d(1, 1, 1)*.999, REFR),//Glas
		Sphere(600, Vector3d(50, 681.6 - .27, 81.6), Vector3d(12, 12, 12), Vector3d(), DIFF) //Lite
	};

}



