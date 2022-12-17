#include <stdio.h>
#include <stdlib.h>
#define N 3

int main(){
int matrix[3][3];
int x[3],y[3],z[3];
int i=0;

while (i < N){
    scanf("%d", &x[i]);
    scanf("%d", &y[i]);
    scanf("%d", &z[i]);
    ++i;
}

matrix[0][0] = x[0];
matrix[0][1] = x[1];
matrix[0][2] = x[2];
matrix[1][0] = y[0];
matrix[1][1] = y[1];
matrix[1][2] = y[2];
matrix[2][0] = z[0];
matrix[2][1] = z[1];
matrix[2][2] = z[2];

int V = matrix[0][0]*matrix[1][1]*matrix[2][2]
    +matrix[2][0]*matrix[0][1]*matrix[1][2]
    +matrix[1][0]*matrix[2][1]*matrix[0][2]
    -matrix[2][0]*matrix[1][1]*matrix[0][2]
    -matrix[0][0]*matrix[2][1]*matrix[1][2]
    -matrix[1][0]*matrix[0][1]*matrix[2][2];
printf("%d", abs(V));

return 0;
}
