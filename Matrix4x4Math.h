#pragma once
#include "Matrix4x4.h"
#include <Novice.h>

class Matrix4x4Math {

private:

	Matrix4x4 resultAdd;
	Matrix4x4 resultSubtract;
	Matrix4x4 resultMultiply;
	Matrix4x4 inverseM1;
	Matrix4x4 inverseM2;
	Matrix4x4 transposeM1;
	Matrix4x4 transposeM2;
	Matrix4x4 identity;

	Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);
	Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
	Matrix4x4 Inverse(const Matrix4x4& m);
	Matrix4x4 Transpose(const Matrix4x4& m);
	Matrix4x4 MakeIdentity();

	static const int kRowHeight = 20;
	static const int kColumnWidth = 60;

	void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix,const char*label);

	public: 

	Matrix4x4Math();
	~Matrix4x4Math();
	void Math(const Matrix4x4& m1, const Matrix4x4& m2);
	void Draw();
};
