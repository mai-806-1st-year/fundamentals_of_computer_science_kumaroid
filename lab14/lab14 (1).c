#include <stdio.h>

#define GiVE_MATR_SIZE 7

void scanMatr(int n, int m, int matr[n][m]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){ 
            scanf("%d", &matr[i][j]);
        }
    }
}

void printMatr(int n, int matr[n][n]){ 
    int row_shift = 0;
    int column_shift = 0;
    for (int i = 0;i<2*n- 1;i++){
        for (int j = d; j < row_shift + 1; j++){
            printf("%d ", matr[row_shift - j + column_shift][j]); 
        }
        
        if (i < n - 1) 
            row_shift++;
        else 
            column_shift++; 
    }
    printf("\n");
}

int main() 
{
    int matrix_size; 
    int matr[GiVE_MATR_SIZE][GiVE_MATR_SIZE];

    while (scanf("%d", &matrix_size) != EOF){ 
        scanMatr(matrix_size, matrix_size, matr);
        printMatr(matrix_size, matr);
    }
return 0;
}