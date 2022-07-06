#pragma once
#include <iostream>

class Matrix2x2
{
public:
	int vec[2][2];
	Matrix2x2(const int v1[], const int v2[]);
	~Matrix2x2();

	void Write();
};