#include "fastmath.h"
#include "matrix.h"

API void Mult4x4(const float* restrict left, const float* restrict right, float* restrict out) {
	/*
		0 1 2 3
		4 5 6 7
		8 9 10 11
		12 13 14 15
	*/
    out[0] = left[0] * right[0] + left[1] * right[4] + left[2] * right[8] + left[3] * right[12];
    out[1] = left[0] * right[1] + left[1] * right[5] + left[2] * right[9] + left[3] * right[13];
    out[2] = left[0] * right[2] + left[1] * right[6] + left[2] * right[10] + left[3] * right[14];
    out[3] = left[0] * right[3] + left[1] * right[7] + left[2] * right[11] + left[3] * right[15];

    out[4] = left[4] * right[0] + left[5] * right[4] + left[6] * right[8] + left[7] * right[12];
    out[5] = left[4] * right[1] + left[5] * right[5] + left[6] * right[9] + left[7] * right[13];
    out[6] = left[4] * right[2] + left[5] * right[6] + left[6] * right[10] + left[7] * right[14];
    out[7] = left[4] * right[3] + left[5] * right[7] + left[6] * right[11] + left[7] * right[15];

    out[8]  = left[8] * right[0] + left[9] * right[4] + left[10] * right[8] + left[11] * right[12];
    out[9]  = left[8] * right[1] + left[9] * right[5] + left[10] * right[9] + left[11] * right[13];
    out[10] = left[8] * right[2] + left[9] * right[6] + left[10] * right[10] + left[11] * right[14];
    out[11] = left[8] * right[3] + left[9] * right[7] + left[10] * right[11] + left[11] * right[15];

    out[12] = left[12] * right[0] + left[13] * right[4] + left[14] * right[8] + left[15] * right[12];
    out[13] = left[12] * right[1] + left[13] * right[5] + left[14] * right[9] + left[15] * right[13];
    out[14] = left[12] * right[2] + left[13] * right[6] + left[14] * right[10] + left[15] * right[14];
    out[15] = left[12] * right[3] + left[13] * right[7] + left[14] * right[11] + left[15] * right[15];
}


API void TransformPosition(Vec3* pos, Mat4* mat, Vec3* result) {
    result->X = pos->X * mat->Rows.Row0.X + pos->Y * mat->Rows.Row1.X + pos->Z * mat->Rows.Row2.X + mat->Rows.Row3.X;
    result->Y = pos->X * mat->Rows.Row0.Y + pos->Y * mat->Rows.Row1.Y + pos->Z * mat->Rows.Row2.Y + mat->Rows.Row3.Y;
    result->Z = pos->X * mat->Rows.Row0.Z + pos->Y * mat->Rows.Row1.Z + pos->Z * mat->Rows.Row2.Z + mat->Rows.Row3.Z;
}

API void TransformVector(Vec3* vec, Mat4* mat, Vec3* result) {
    result->X = vec->X * mat->Rows.Row0.X + vec->Y * mat->Rows.Row1.X + vec->Z * mat->Rows.Row2.X;
    result->Y = vec->X * mat->Rows.Row0.Y + vec->Y * mat->Rows.Row1.Y + vec->Z * mat->Rows.Row2.Y;
    result->Z = vec->X * mat->Rows.Row0.Z + vec->Y * mat->Rows.Row1.Z + vec->Z * mat->Rows.Row2.Z;
}