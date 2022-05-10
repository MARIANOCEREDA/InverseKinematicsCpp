
#include "./headers/Robot.h"
#include "headers/MatrixOperations.h"
#include <cmath>

#define M_PI 3.141592653589793238462643383279502884

int main(int argc, char* argv[], char* envp[]) {
	//Tool Matrix
	double tool[4][4] = { {1, 0, 0, 0},{0,1,0,0},{0,0,1,0}, {0, 0, 0, 1} };

	//Base Matrix
	double base[4][4] = { {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1} };

	//Denavit-Hartenberg Matrix
	double dh[6][4] = { {0,0.575,0.175,M_PI / 2},{0,0,0.89,0},{0,0,M_PI / 2,0},{1.05,0,-M_PI / 2,0},{0,0,0,M_PI / 2},{0,0.185,0,0} };

	//T Matrix
	double T[4][4] = { {0.7959,0.2612,0.5461,0.6795},{0.0177,0.8917,-0.4522,0.6699},{-0.6051,0.3696,0.7051,2.6586},{0,0,0,1} };

	double mrot[4][4];
	rot(base, M_PI, mrot, 'x');
	print(mrot);
	system("pause");
}
