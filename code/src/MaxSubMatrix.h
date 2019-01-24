#ifndef MAXSUBMATRIX_H
#define MAXSUBMATRIX_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int** Matrix;  /* typedef point to point as MAtrix*/

int MaxSubMatrixSum_A1( Matrix A, int N ); /* Algorithm 1 with the time complexity of O(N^6) */
int MaxSubMatrixSum_A2( Matrix A, int N ); /* Algorithm 2 with the time complexity of O(N^4) */
int MaxSubMatrixSum_Bonus( Matrix A, int N );  /* Algorithm 3 with the time complexity of O(N^3) */

#endif
