/**
 * @file LeastSquare.c
 * @brief LeastSquare.c
 */

#include <stdlib.h>
#include "NR.h"

/**
 * @brief solve the leastsquare solution for a system of linear equations.
 * @param m length of first axis of A
 * @param n length of second axis of A
 * @param A matrix of shape m * n (m >= n)
 * @param b constant vector
 * @returns least square solution of A x = b
 */
double *LeastSquare(int m, int n, double **A, double *b)
{
    if (m<n)
    {
        return NULL;
    }

    double *res = malloc(n * sizeof(double));
    double *Ab = malloc(n * sizeof(double));
    double *AA = malloc((n * n) * sizeof(double));

    // A.T times A
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            AA[i * n + j] = 0;
            for (int k = 0; k < m; k++)
            {
                AA[i * n + j] += A[k][i] * A[k][j];
            }
        }
    }

    //transpose of matrix A times b
    for (int i = 0; i < n; i++)
    {
        Ab[i] = 0;
        for (int j = 0; j < m; j++)
        {
            Ab[i] += A[j][i] * b[j];
        }
    }

    //solve the equation AA x = Ab
    res = GaussEli(n, AA, Ab);

    //free the memory space allocated before
    free(AA);
    free(Ab);
    return res;
}
