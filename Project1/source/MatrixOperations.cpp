
#include "../headers/MatrixOperations.h"


void inverse(double m[4][4], static double result[4][4]) {

}


/**
* @name -> product
* @type -> function
* @return void -> no return value
* @description -> Calculates the product between 2 matrix. Te size of the matrix is fix (4x4).
* @parameters m1[][] -> first matrix of the product
* @parameters m2[][] -> second matrix of the product
* @parameters result[][] -> result containing the product
*/

void product(double m1[4][4], double m2[4][4],double result[4][4]) {

	result[0][0] = 0;
	int k = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			result[i][j] = result[i][j] + m1[i][j] * m2[i][j];
		}
	}

}
