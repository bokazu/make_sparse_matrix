#include "all.h"

using namespace std;

int main()
{
    int n = 10;
    int *col = new int[n * n];
    int *row = new int[n * n];
    double *val = new double[n * n];
    int index = 0;
    double mtmp;
    double prob = 0.3;

    FILE *file;
    file = fopen("sparse_matrix_sample1.txt", "w");
    if (file == NULL)
    {
        // fopen失敗
        // streamにstdout指定なので実質printfと同じ
        fprintf(stdout, "fopen error fp[%p]\n", file);
        return -1;
    }

    // make sparse matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            mtmp = (double)rand() / RAND_MAX;
            if (mtmp < prob)
            {
                row[index] = i;
                col[index] = j;
                val[index] = 1.0;
                index++;
                //対称成分も格納する
                if (i != j)
                {
                    row[index] = j;
                    col[index] = i;
                    val[index] = 1.0;
                    index++;
                }
            }
        }
    }

    // output to file
    fprintf(file, "%d %d %d\n", n, n, index);
    for (int i = 0; i < index; ++i)
    {
        fprintf(file, "%d %d %2.2f\n", row[i], col[i], val[i]);
    }
}