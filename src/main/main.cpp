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
using namespace OpRt;

#define  width 800
#define  height 800

//随机函数，返回一个在[0,1]区间的浮点数
double drand48() {
	return (double)rand() / (double)RAND_MAX;
}


Vector3d window[width][height];


void RayTrace(const Ray &cam, const std::vector<Sphere *> spheres, const std::vector<Light *> lights){
	double fov = 75; //视角
	double fac = radian(fov);//将角度制转化为弧度制
	for (int x = 0; x < width; ++x){
		for (int y = 0; y < height; ++y){
			Vector3d dir_( (2 * ((x + 0.5) / width) - 1) * fac, (1-2*((y+0.5)/height)) * fac,-1);
			normalize(dir_);
			Color color = Ray(cam.origin(), dir_).trace(spheres, 0, lights);
			window[x][y] = color;
		}
	}

}

inline double clamp(double x)
{
	return x < 0 ? 0 : x>1 ? 1 : x;
}

inline int toInt(double x)//伽马矫正
{
	return int(pow(clamp(x), 1 / 2.2) * 255 + .5);
}


int main(){
	
	std::vector<Sphere*> spheres;
	
	//几个球的位置，来作为康奈尔盒子
 	//spheres.push_back(new Sphere(1e5, Vector3d(1e5 + 1, 40.8, 81.6), Vector3d(), Vector3d(.75, .25, .25), DIFF));//Left
 	//spheres.push_back(new Sphere(1e5, Vector3d(-1e5 + 99, 40.8, 81.6), Vector3d(), Vector3d(.25, .25, .75), DIFF)); //Rght
 	//spheres.push_back(new Sphere(1e5, Vector3d(50, 40.8, 1e5), Vector3d(), Vector3d(.75, .75, .75), DIFF)); //Back
 	//spheres.push_back(new Sphere(1e5, Vector3d(50, 40.8, -1e5 + 170), Vector3d(), Vector3d(), DIFF));//Frnt
 	//spheres.push_back(new Sphere(1e5, Vector3d(50, 1e5, 81.6), Vector3d(), Vector3d(.75, .75, .75), DIFF));//Botm
 	//spheres.push_back(new Sphere(1e5, Vector3d(50, -1e5 + 81.6, 81.6), Vector3d(), Vector3d(.75, .75, .75), DIFF));//Top

 	//spheres.push_back(new Sphere(16.5, Vector3d(27, 16.5, 47), Vector3d(), Vector3d(1, 1, 1)*.999, SPEC));//Mirr
 	//spheres.push_back(new Sphere(16.5, Vector3d(73, 16.5, 78), Vector3d(), Vector3d(1, 1, 1)*.999, REFR));//Glas
	//spheres.push_back(new Sphere(600, Vector3d(50, 681.6 - .27, 81.6), Vector3d(12, 12, 12), Vector3d(), DIFF));//Lite 灯


	spheres.push_back(new Sphere(16.5, Vector3d(27, 16.5, 47), Vector3d(), Vector3d(.75, .25, .25), SPEC));
	spheres.push_back(new Sphere(16.5, Vector3d(73, 16.5, 78), Vector3d(), Vector3d(.25, .25, .75), DIFF));
	spheres.push_back(new Sphere(16.5, Vector3d(0, 16.5, 78), Vector3d(), Vector3d(.75, .25, .75), DIFF));



	spheres.push_back(new Sphere(1e5, Vector3d(50.0, -1e5 , 81.6), Vector3d(), Vector3d(.75, .75, .75), DIFF));//floor
	spheres.push_back(new Sphere(1e5, Vector3d(50, 40.8, -1e5-50), Vector3d(), Vector3d(0.25, 0.75, 0.25),DIFF));//BackGround
	

	std::vector<Light *> lights;
	lights.push_back(new PointLight(Vector3d(300, 300, 300)));

	Ray cam(Vector3d(50, 52, 150.6), normalize(Vector3d(0, -0.042612, -1)));


	RayTrace(cam, spheres, lights);

	FILE *f = fopen("image.ppm", "w");         // Write image to PPM file.
	fprintf(f, "P3\n%d %d\n%d\n", width, height, 255);
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			fprintf(f, "%d %d %d ", toInt(window[y][x].x_), toInt(window[y][x].y_), toInt(window[y][x].z_));
		}
	}


}

