#include <stdio.h>
#include <stdlib.h>

void out(int N, int m[], int n_g){
  int b[N*N];
  for (int k = n_g%(N*N) - 1; k >= 0; --k){
    b[k] = m[N*N - (n_g%(N*N) - k)];
  }
  for (int k = 0; k < N*N - n_g%(N*N); k++){
    b[k + n_g%(N*N)] = m[k];
  }
  printf("OUT:\n");
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++) {
      printf("%d ", b[i * N + j]);
    }
    printf("\n");
  }
}


int main(){
  int N;
  int n_g;
  printf("GROUP NUMBER\n");
  scanf("%d", &n_g);
  printf("MATRIX SIZE:\n");
  scanf("%d", &N);
  int m[N*N];
  printf("MATRIX:\n");

  for (int k = 0; k != N*N; k++)
  {
      scanf("%d", &m[k]);
  }
  out(N, m, n_g);
  
  return 0;
}
