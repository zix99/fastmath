#include "vector.h"

float length3f(Vec3 vec) {
	return sqrt(vec.X*vec.X + vec.Y*vec.Y + vec.Z*vec.Z);
}

float length4f(Vec4 vec) {
	return sqrt(vec.X*vec.X + vec.Y*vec.Y + vec.Z*vec.Z + vec.W*vec.W);
}