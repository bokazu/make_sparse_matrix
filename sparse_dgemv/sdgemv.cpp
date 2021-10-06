#include "all.h"

using namespace std;

int main()
{
    int n, elements;
    int row_num, col_num;

    string filename("sample/sample1.txt");  // filename of sparse matrix data
    cout << "get size of matrix\n";
    get_matrix_size(filename, n, elements);
    cout << "n = " << n << endl;
    cout << "elements = " << elements << endl;

    // set row,col,val,x,v
    int *row = new int[elements];
    int *col = new int[elements];
    double *val = new double[elements];
    double *x = new double[n];
    double *v = new double[n];

    // Input Data of sparse matrix
    cout << "input matirx data\n";
    input_data(filename, elements, row, col, val);
    FILE *file;
    file = fopen("output3.txt", "w");
    if (file == NULL)
    {
        // fopen失敗
        // streamにstdout指定なので実質printfと同じ
        fprintf(stdout, "fopen error fp[%p]\n", file);
        return -1;
    }

    //配列の初期化
    Initiailize_vec(n, v);
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;

    for (int i = 0; i < elements; i++)
    {
        row_num = row[i];
        col_num = col[i];
        v[row_num] += val[i] * x[col_num];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "v[" << i << "]=" << v[i] << endl;
    }

    delete[] row;
    delete[] col;
    delete[] val;
    delete[] x;
    delete[] v;
}