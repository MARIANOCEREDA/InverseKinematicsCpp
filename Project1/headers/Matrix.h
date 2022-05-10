#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 4
#define rows 4
#define cols 4

class Matrix {
private:
	double m[4][4];
public:
	Matrix();
	Matrix(double matrix[4][4]);
	Matrix operator*(const Matrix& m2);
	void inverse(double minv[4][4], double& det);
	void rot(double angle, double mrot[4][4], char axis);
	void translate(double* xyz, double mtransl[4][4]);
	void identityMatrix(double identity[4][4]);
	void print();
};





