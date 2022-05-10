
#include "../headers/MatrixOperations.h"

Matrix::Matrix(){
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++) {
            m[i][j] = 0;
        }
    }
}

Matrix::Matrix(double matrix[4][4]) {
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++) {
            m[i][j] = matrix[i][j];
        }
    }
}

/**
* @name -> inverse
* @type -> function
* @return void -> no return value
* @description -> Calculates the inverse matrix of m,
* @parameters m1[][] -> matrix to be calculated
* @parameters m[][] -> result (inverse matrix of m)
*/

void Matrix::inverse(double minv[4][4],double &det) {
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
                this->m[i][j] = this->m[i][j] - factor * m[k][j];
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
                    L[i][j] = this->m[i][j] / m[j][j];
                    this->m[i][j] = 0;
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
                this->m[i][n] = D[i];

            }

            // Rutina que aplica la sustitución hacia atras

            X[n - 1] = this->m[n - 1][n] / this->m[n - 1][n - 1];

            // Determinación de las raíces restantes

            for (i = n - 2; i > -1; i--) {
                sum = 0;
                for (j = i + 1; j < n; j++) {
                    sum = sum + this->m[i][j] * X[j];
                }
                X[i] = (this->m[i][n] - sum) / this->m[i][i];
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
* @name -> rot
* @type -> function
* @return void -> no return value
* @description -> Rotate the matrix around x,y or z axis.
* @parameters m1[][] -> matrix to be rotated
* @parameters m2[][] -> rotated matrix.
* @parameters angle -> angle to be rotated.
* @parameteres axis -> rotation axis.
*/

void Matrix::rot(double angle, double mrot[4][4],char axis)
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
};

/**
* @name -> translate
* @type -> method
* @return void -> no return value
* @description -> Translate the identity from the {0,0,0} to xyz
* @parameters xyz ->
* @parameters result[][] -> result containing the product
*/

void Matrix::translate(double* xyz,double mtransl[4][4])
{
    identityMatrix(mtransl);
    mtransl[0][3] = xyz[0];
    mtransl[1][3] = xyz[1];
    mtransl[2][3] = xyz[2];
}

void Matrix::identityMatrix(double identity[4][4])
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

void Matrix::print() {
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++) {
            std::cout << this->m[i][j] << " " ;
        }
        std::cout << "\n";
    }
}

Matrix Matrix::operator*(const Matrix& m2)
{
    double result[N][N];
    for (int a = 0; a < N; a++) {
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < N; j++) {
                sum += this->m[i][j] * m2.m[j][a];
            }
            result[i][a] = sum;
        }
    }

    return Matrix(result);
}
