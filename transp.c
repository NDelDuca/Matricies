#include <stdio.h>
#include <stdlib.h>


void main(int argc, char const *argv[]){

  int i;
  int j;
  char *p;

  int n = strtol(argv[1], &p, 10);

  double *A = malloc(n * sizeof(float));

  // build the matrix
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      A[i * n + j] = 1;
    }
  }

  // transpose the matrix
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      A[i * n + j] = 2;
    }
  }

  free(A);

}
