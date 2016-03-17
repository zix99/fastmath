#include "vector.h"

#ifndef __MATRIX_H__
#define __MATRIX_H__

typedef union {
	struct {
		Vec4 Row0, Row1, Row2, Row3;
	} Rows;
	float Values[16];
} Mat4;

#endif