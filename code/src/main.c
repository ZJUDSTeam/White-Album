#include "MaxSubMatrix.h"
#define true (1)
#define TestDataSize (100000)  /* the scale of the test data */
void CreateRandSample( void );  /* function used to generate test data */

int main(void){

    int i, j, k, choice;
    int n; /* size of matrix */
    int iter; /* iteration number */
    Matrix A; /* pointer to pointer to matrix */

    clock_t start, stop;
    double total; /* records the total runtime */
    int res;
    char cont; /* judge whether to continue main loop of the test program*/

    FILE *fp;

    CreateRandSample(); /* generate test data stored in test.dat */

    /* open the test data file */
    if( (fp = fopen( "test.dat","r")) == NULL )
    {
        printf( "Open File Failed\n");
        exit(1);
    }

    /* main loop */
    while( true )
    {
        /* select the algorithm to test */
        printf("Please select the algorithm you want to test:\n");
        printf( "1.Algorithm 1 O(N^6)\n2.Algorithm 2 O(N^4)\n3.Algorithm 3 O(N^3) (Bonus)\n");
        printf( "Your Choice: ");
        while( true )
        {
            scanf( "%d", &choice);
            if( choice <=3 && choice >=1 ) /* Judge the validity of input */
                break;
            printf( "Invalid Input\nYour Choice: ");

        }
        /* get the matrix size(N) */
        printf( "Please Input the value of N: ");
        while( true )
        {
            scanf( "%d", &n);
            if( n >= 2  && n <= 100 ) /* Judge the validity of matrix size [2-100] */
                break;
            printf( "Invalid Input\nPlease Input the value of N: ");

        }
        /* get the number of iteration to run */
        printf( "Please Input the numbers of iteration(K): ");
        while( true )
        {
            scanf("%d", &iter);
            if( iter >= 1 ) /* Judge the validity of iteration number */
                break;
            printf( "Invalid Input\nPlease Input the numbers of iteration(K): ");

        }


        /* allocate memory block to store matrix */
        A = (int**)malloc(sizeof(int*)*n);
        /*Judge whether sufficient memory available*/
        if( A == NULL )
        {
            printf( "Out of Space!");
            exit(1);
        }
        /* allocate memory block to store each row of the matrix */
        for( i = 0; i < n; i++)
        {
            A[i] = (int*)malloc(sizeof(int)*n);
            /*Judge whether sufficient memory available*/
            if( A[i] == NULL )
            {
                printf( "Out of Space!");
                exit(1);
            }
        }

        start = clock(); /* records the ticks at the beginning */

        /* repeat for the times of iteration number */
        for( k = 0; k < iter; k++ ){

            /* read the test data of Matrix*/
            for( i = 0; i < n; i++ )
                for( j = 0;j<n;j++ )
                    fscanf( fp, "%d", &A[i][j]);
            /* choose the algorithm to run */
            switch(choice){
                case 1:
                    res = MaxSubMatrixSum_A1( A, n ); /* Algorithm 1 with the time complexity of O(N^6) */
                    break;
                case 2:
                    res = MaxSubMatrixSum_A2( A, n ); /* Algorithm 2 with the time complexity of O(N^4) */
                    break;
                case 3:
                    res = MaxSubMatrixSum_Bonus( A, n ); /* Algorithm better than the above two with time complexity of O(N^3) */
                    break;
                default:
                    break;
            }
        }

        free( A );

        stop = clock(); /* records the ticks at the end */
        total = ((double)(stop - start))/CLK_TCK; /* get the total runtime (CLK_TCK = ticks per second) */


        /* Ticks: the number of elapsed ticks during the runtime *
         * Total time : total runtime of repeating the chosen algorithm for iter times
         * Duration time : average time of the chosen algorithm
         */
        printf( "===========================================================\n");
        printf( "| Iterations(K) | Ticks | Total Time(sec) | Duration(sec) |\n");
        printf( "|%15d|%7ld|%17lf|%15f|\n", iter, stop-start, total, total/iter);
        printf( "===========================================================\n");

        /* Input the value of cont */
        getchar();
        printf( "Continue?(Y/N)");
        scanf( "%c", &cont);
        if( cont != 'Y' && cont != 'y' )
            break;

    }

    return 0;

}


void CreateRandSample( void )
{
    int i;
    FILE *fp = NULL;

    srand((unsigned)time(NULL)); /* set the seed for the random number generator */

    /* Create the test data file test.dat */
    if( (fp = fopen( "test.dat", "w")) == NULL )
    {
        printf("Create File Failed\n");
        exit(1);
    }

    /* generate 100000 random number from -20 to 20 and write to test.dat */
    for( i = 0; i < TestDataSize; i++)
        fprintf( fp, "%d ", rand()%40-20 );

    fclose(fp);
    return;

}
