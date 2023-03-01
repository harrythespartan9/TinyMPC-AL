#pragma once

#include <math.h>

#include "slap/slap.h"

//========================================
// Acrobot model parameters
//========================================
struct tiny_Model_Acrobot {
  double g;
  double m[2];
  double l[2];
  double J[2];
  double umin;
  double umax;
};


//========================================
// Codes generated from julia/acrobot
// Discrete dynamics with predefined model params
//========================================
void tiny_Dynamics_RK4_Raw(double* xn, const double* x, const double* u) {
  xn[0] = 0.16666666666666666 * (0.1 * (0.1 * u[0] + x[3]) * cos(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.1 * cos(x[2]) * x[3] + 0.2 * (0.05 * u[0] + x[3]) * cos(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.2 * (0.05 * u[0] + x[3]) * cos(0.05 * tan(x[4]) * x[3] + x[2])) + x[0];
  xn[1] = 0.16666666666666666 * (0.2 * (0.05 * u[0] + x[3]) * sin(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.2 * (0.05 * u[0] + x[3]) * sin(0.05 * tan(x[4]) * x[3] + x[2]) + 0.1 * (0.1 * u[0] + x[3]) * sin(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.1 * sin(x[2]) * x[3]) + x[1];
  xn[2] = 0.16666666666666666 * (0.1 * (0.1 * u[0] + x[3]) * tan(0.1 * u[1] + x[4]) + 0.4 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + 0.1 * tan(x[4]) * x[3]) + x[2];
  xn[3] = 0.1 * u[0] + x[3];
  xn[4] = 0.1 * u[1] + x[4];
}

void tiny_Dynamics_RK4(Matrix xn, const Matrix x, const Matrix u)
{
  tiny_Dynamics_RK4_Raw(xn.data, x.data, u.data);
}

//========================================
// Codes generated from julia/acrobot
// Jacobians of discrete dynamics with predefined model params
//========================================
void tiny_GetJacobianA_Raw(double* A, const double* x, const double* u) 
{
  A[0] = 1;
  A[1] = 0;
  A[2] = 0;
  A[3] = 0;
  A[4] = 0;
  A[5] = 0;
  A[6] = 1;
  A[7] = 0;
  A[8] = 0;
  A[9] = 0;
  A[10] = 0.16666666666666666 * (-0.2 * (0.05 * u[0] + x[3]) * sin(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + -0.2 * (0.05 * u[0] + x[3]) * sin(0.05 * tan(x[4]) * x[3] + x[2]) + -0.1 * (0.1 * u[0] + x[3]) * sin(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + -0.1 * sin(x[2]) * x[3]);
  A[11] = 0.16666666666666666 * (0.1 * (0.1 * u[0] + x[3]) * cos(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.1 * cos(x[2]) * x[3] + 0.2 * (0.05 * u[0] + x[3]) * cos(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.2 * (0.05 * u[0] + x[3]) * cos(0.05 * tan(x[4]) * x[3] + x[2]));
  A[12] = 1;
  A[13] = 0;
  A[14] = 0;
  A[15] = 0.16666666666666666 * (0.2 * cos(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.2 * cos(0.05 * tan(x[4]) * x[3] + x[2]) + 0.1 * cos(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.1 * cos(x[2]) + -0.01 * (0.05 * u[0] + x[3]) * sin(0.05 * tan(x[4]) * x[3] + x[2]) * tan(x[4]) + -0.01 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) * sin(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + -0.01 * (0.1 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) * sin(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]));
  A[16] = 0.16666666666666666 * (0.2 * sin(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.2 * sin(0.05 * tan(x[4]) * x[3] + x[2]) + 0.1 * sin(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.1 * sin(x[2]) + 0.01 * (0.1 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) * cos(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.01 * (0.05 * u[0] + x[3]) * cos(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) * tan(0.05 * u[1] + x[4]) + 0.01 * (0.05 * u[0] + x[3]) * cos(0.05 * tan(x[4]) * x[3] + x[2]) * tan(x[4]));
  A[17] = 0.16666666666666666 * (0.4 * tan(0.05 * u[1] + x[4]) + 0.1 * tan(0.1 * u[1] + x[4]) + 0.1 * tan(x[4]));
  A[18] = 1;
  A[19] = 0;
  A[20] = 0.16666666666666666 * (-0.01 * pow(0.05 * u[0] + x[3], 2) * (1 + pow(tan(0.05 * u[1] + x[4]), 2)) * sin(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + -0.01 * (1 + pow(tan(0.05 * u[1] + x[4]), 2)) * (0.05 * u[0] + x[3]) * (0.1 * u[0] + x[3]) * sin(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + -0.01 * (1 + pow(tan(x[4]), 2)) * (0.05 * u[0] + x[3]) * sin(0.05 * tan(x[4]) * x[3] + x[2]) * x[3]);
  A[21] = 0.16666666666666666 * (0.01 * pow(0.05 * u[0] + x[3], 2) * (1 + pow(tan(0.05 * u[1] + x[4]), 2)) * cos(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.01 * (1 + pow(tan(0.05 * u[1] + x[4]), 2)) * (0.05 * u[0] + x[3]) * (0.1 * u[0] + x[3]) * cos(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.01 * (1 + pow(tan(x[4]), 2)) * (0.05 * u[0] + x[3]) * cos(0.05 * tan(x[4]) * x[3] + x[2]) * x[3]);
  A[22] = 0.16666666666666666 * (0.1 * (1 + pow(tan(0.1 * u[1] + x[4]), 2)) * (0.1 * u[0] + x[3]) + 0.4 * (1 + pow(tan(0.05 * u[1] + x[4]), 2)) * (0.05 * u[0] + x[3]) + 0.1 * (1 + pow(tan(x[4]), 2)) * x[3]);
  A[23] = 0;
  A[24] = 1;
}

void tiny_GetJacobianB_Raw(double* B, const double* x, const double* u) 
{
  B[0] = 0.16666666666666666 * (0.01 * cos(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.01 * cos(0.05 * tan(x[4]) * x[3] + x[2]) + 0.01 * cos(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + -0.0005 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) * sin(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + -0.0005 * (0.1 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) * sin(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]));
  B[1] = 0.16666666666666666 * (0.01 * sin(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.01 * sin(0.05 * tan(x[4]) * x[3] + x[2]) + 0.01 * sin(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.0005 * (0.1 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) * cos(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.0005 * (0.05 * u[0] + x[3]) * cos(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) * tan(0.05 * u[1] + x[4]));
  B[2] = 0.16666666666666666 * (0.02 * tan(0.05 * u[1] + x[4]) + 0.01 * tan(0.1 * u[1] + x[4]));
  B[3] = 0.1;
  B[4] = 0;
  B[5] = 0.16666666666666666 * (-0.0005 * pow(0.05 * u[0] + x[3], 2) * (1 + pow(tan(0.05 * u[1] + x[4]), 2)) * sin(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + -0.0005 * (1 + pow(tan(0.05 * u[1] + x[4]), 2)) * (0.05 * u[0] + x[3]) * (0.1 * u[0] + x[3]) * sin(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]));
  B[6] = 0.16666666666666666 * (0.0005 * pow(0.05 * u[0] + x[3], 2) * (1 + pow(tan(0.05 * u[1] + x[4]), 2)) * cos(0.05 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]) + 0.0005 * (1 + pow(tan(0.05 * u[1] + x[4]), 2)) * (0.05 * u[0] + x[3]) * (0.1 * u[0] + x[3]) * cos(0.1 * (0.05 * u[0] + x[3]) * tan(0.05 * u[1] + x[4]) + x[2]));
  B[7] = 0.16666666666666666 * (0.01 * (1 + pow(tan(0.1 * u[1] + x[4]), 2)) * (0.1 * u[0] + x[3]) + 0.02 * (1 + pow(tan(0.05 * u[1] + x[4]), 2)) * (0.05 * u[0] + x[3]));
  B[8] = 0;
  B[9] = 0.1;
}

void tiny_GetJacobians(Matrix A, Matrix B, const Matrix x, const Matrix u) 
{
  tiny_GetJacobianA_Raw(A.data, x.data, u.data);
  tiny_GetJacobianB_Raw(B.data, x.data, u.data);
}