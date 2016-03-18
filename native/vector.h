#include <math.h>

#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct {
	float X,Y,Z;
} Vec3;

typedef struct {
	float X,Y,Z,W;
} Vec4;

float length3f(Vec3 vec);
float length4f(Vec4 vec);

#endif