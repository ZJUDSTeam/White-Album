#include "MaxSubMatrix.h"

/**
 * @brief  Algorithm similar to Algorithm 1
 * enumerate every SubMatrix and compute its sum
 * @param A secondary point to memory space stores matrix
 * @param N Matrix Rank
 * @return MaxSum MaxSubMatrixSum
 */

int MaxSubMatrixSum_A1( Matrix A, int N )
{

    int i, j;
    int ThisSum, MaxSum, TopRow, BottomRow, LeftCol, RightCol;
    MaxSum = 0; /* variable to store the MaxSubMatrixSum */

    for( TopRow = 0; TopRow < N; TopRow++ )  /* set the top row */
        for( BottomRow = TopRow; BottomRow < N; BottomRow++)  /* set the bottom row by outer loop */
            for( LeftCol = 0; LeftCol < N; LeftCol++)   /* set the left col */
                for( RightCol = LeftCol; RightCol < N; RightCol++)  /* set the right col by the inner loop */
                {
                    ThisSum = 0;    /* the maximum submatrix sum is 0 if all the integers are negative */
                    for( i = TopRow; i <= BottomRow; i++)
                        for( j = LeftCol; j <= RightCol; j++)
                            ThisSum += A[i][j];     /* calculate the matrix sum with boundary rows and columns */

                    if( ThisSum > MaxSum )
                        MaxSum = ThisSum;   /* compare ThisSum with MaxSum and if ThisSum > MaxSum,update MaxSum */
                }
    return MaxSum;
}


/**
 * @brief  Use algorithm similar to Algorithm 2
 * Calculate the sum of elements  between TopRow to BottomRow for every column
 * and store in an array, thus compressing 2D array in 1D array
 * then use algorithm 2 to calculate the MaxSubsequenceSum
 * @param A secondary point to memory space stores matrix
 * @param N Matrix Rank
 * @return MaxSum MaxSubMatrixSum
 */

int MaxSubMatrixSum_A2( Matrix A, int N )
{
    
    int i, j;
    int ThisSum, MaxSum;
    int TopRow, BottomRow;
    int temp[N];
    MaxSum = 0; /* variable to store the MaxSubMatrixSum */

    for( TopRow = 0; TopRow < N; TopRow++ )
    {
        memset( temp, 0, sizeof(temp)); /*Initialize all elements of temp as 0 */
        for( BottomRow = TopRow; BottomRow < N; BottomRow++)
        {
            /* calculate the sum of elements  between TopRow and BottomRow for every column i */
            for( i = 0; i < N; i++)
                temp[i] += A[BottomRow][i];

            for( i = 0; i < N; i++)
            {
                ThisSum = 0;    /* the maximum submatrix sum is 0 if all the integers are negative */
                for( j = i; j < N; j++ )
                {
                    ThisSum += temp[j];

                    if( ThisSum > MaxSum )
                        MaxSum = ThisSum;    /* compare ThisSum with MaxSum and if ThisSum > MaxSum,update MaxSum */
                }
            }

        }
    }

    return MaxSum;
}



/**
 * @brief  Use algorithm similar to Algorithm 4
 * Calculate the sum of elements  between TopRow to BottomRow for every column
 * and store in an array, thus compressing 2D array into 1D array
 * then use algorithm 4 to calculate the MaxSubsequenceSum
 * @param A secondary point to memory space stores matrix
 * @param N Matrix Rank
 * @return MaxSum MaxSubMatrixSum
 */

int MaxSubMatrixSum_Bonus( Matrix A, int N )
{
    
    int i;
    int ThisSum, MaxSum;
    int TopRow, BottomRow;
    int temp[N];
    MaxSum = 0; /* variable to store the final output */

    for( TopRow = 0; TopRow < N; TopRow++ )
    {
        memset( temp, 0, sizeof(temp)); /*Initialize all elements of temp as 0 */
        for( BottomRow = TopRow; BottomRow < N; BottomRow++)
        {
            /* calculate the sum of elements  between TopRow to BottomRow for every column i */
            for( i = 0; i < N; i++)
                temp[i] += A[BottomRow][i];

            ThisSum = 0;    /* the maximum submatrix sum is 0 if all the integers are negative */
            for( i = 0; i < N; i++)
            {
                ThisSum += temp[i];

                if( ThisSum > MaxSum )
                    MaxSum = ThisSum;
                else if ( ThisSum < 0 )
                    ThisSum = 0;    /* compare ThisSum with MaxSum and if ThisSum > MaxSum,update MaxSum */
            }
        }
    }

    return MaxSum;
}
