
#include "../headers/MatrixOperations.h"


/**
* @name -> inverse
* @type -> function
* @return void -> no return value
* @description -> Calculates the inverse matrix of m,
* @parameters m1[][] -> matrix to be calculated
* @parameters m[][] -> result (inverse matrix of m)
*/

void inverse(double m[4][4],double minv[4][4],double &det) {
    int8_t i, j, k,n;
    n = N;
    double factor;

    double** L, * D, * X;

    X = new double[n]; D = new double[n];
    L = new double* [n];

    for (j = 0; j < n; j++)
        L[j] = new double[n];

    for (k = 0; k < n - 1; k++) {
        for (i = k + 1; i < n; i++) {
            factor = m[i][k] / m[k][k];
            for (j = k + 1; j < n + 1 ; j++) {
                m[i][j] = m[i][j] - factor * m[k][j];
            }
        }
    }

    // Determinant of the matrix

    det = 1.;
    for (i = 0; i < n; i++) {
        det = det * m[i][i];
    }

    if (det != 0) {

        // Calculate the matrix L (inferior) y U (superior) de la 
        // LU descomposition

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i > j) {
                    L[i][j] = m[i][j] / m[j][j];
                    m[i][j] = 0;
                }
            }
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                L[j][j] = 1;
            }
        }

        // Reoutine for the calculation of the inverse

        for (k = 0; k < n; k++) {

            // Initialize L[i][n] to be used with the matrix L
            for (i = 0; i < n; i++) {
                if (i == k) L[i][n] = 1;
                else  L[i][n] = 0;

            }

            // Forward sustitution with L and the L[i][n] that are calculated in the previous loop

            double sum;
            D[0] = L[0][n];

            for (i = 1; i < n; i++) {
                sum = 0;
                for (j = 0; j < i; j++) {
                    sum = sum + L[i][j] * D[j];
                }
                D[i] = L[i][n] - sum;
            }

            // Esta rutina asigna los D[i] que produce forward para ser utilizados con la matriz U

            for (i = 0; i < n; i++) {
                m[i][n] = D[i];

            }

            // Rutina que aplica la sustitución hacia atras

            X[n - 1] = m[n - 1][n] / m[n - 1][n - 1];

            // Determinación de las raíces restantes

            for (i = n - 2; i > -1; i--) {
                sum = 0;
                for (j = i + 1; j < n; j++) {
                    sum = sum + m[i][j] * X[j];
                }
                X[i] = (m[i][n] - sum) / m[i][i];
            }

            // Esta rutina asigna los X[i] que produce Sustituir como los elementos de la matriz inversa

            for (i = 0; i < n; i++) {
                minv[i][k] = X[i];
            }
        }   // llave de cierre del for para k
    }   // cierre del if

    delete L, D, X;
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

/**
* @name -> rot
* @type -> function
* @return void -> no return value
* @description -> Rotate the matrix around x,y or z axis.
* @parameters m1[][] -> matrix to be rotated
* @parameters m2[][] -> rotated matrix.
* @parameters angle -> angle to be rotated.
* @parameteres axis -> rotation axis.
*/

void rot(double m[4][4],double angle, double mrot[4][4],char axis)
{
    float cosa, sina;
    identityMatrix(mrot);
    cosa = std::cos(angle);
    sina = std::sin(angle);
    
    switch (axis)
    {
    case 'x':
        mrot[1][1] = cosa;
        mrot[2][2] = cosa;
        mrot[2][1] = sina;
        mrot[1][2] = -sina;
        break;
    case 'y':
        mrot[0][0] = cosa;
        mrot[2][2] = cosa;
        mrot[2][0] = -sina;
        mrot[0][2] = sina;
        break;
    case 'z':
        mrot[0][0] = cosa;
        mrot[1][1] = cosa;
        mrot[0][1] = -sina;
        mrot[1][0] = sina;
        break;
    default:
        break;
    }
    /*We replace for the corresponding sines and cosines so the z rotation is produced*/
    
};

void translate(double m[4][4],double* xyz,double mtransl[4][4])
{
    identityMatrix(mtransl);
    mtransl[0][3] = xyz[0];
    mtransl[1][3] = xyz[1];
    mtransl[2][3] = xyz[2];
}

void identityMatrix(double identity[4][4])
{
    /*We fill the identity matrix*/
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++)
        {
            identity[i][j] = 0;
            if (i == j) {
                identity[i][j] = 1;
            }
        }
    }
}

void print(double m[4][4]) {
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++) {
            std::cout << m[i][j] << " " ;
        }
        std::cout << "\n";
    }
}
