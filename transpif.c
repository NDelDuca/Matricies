#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double time_diff(struct timeval st, struct timeval ed){

  double st_ms, ed_ms, diff;

  st_ms = (double)st.tv_sec*1000000 + (double)st.tv_usec;
  ed_ms = (double)ed.tv_sec*1000000 + (double)ed.tv_usec;

  diff = (double)ed_ms - (double)st_ms;

  return diff;
}

void main(int argc, char const *argv[]){

  struct timeval start, end;

  int i;
  int j;
  char *p;
  int row = strtol(argv[1], &p, 10);
  int col = strtol(argv[2], &p, 10);
  int n = row+col;
  int temp;

  double *A = malloc(n * sizeof(float));
  double *At = malloc(n * sizeof(float));

  // build the matrix
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      A[i * n + j] = rand();
    }
  }


  // Print the input matrix

  printf("Input Matrix:\n");

  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      printf("%d\t", A[i * n + j]);
    }
    printf("\n");
  }
  printf("\n");



  // transpose the matrix
  gettimeofday(&start, NULL);
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      temp = At[i * n + j];
      At[i * n + j] = A[j * n + i];
      A[j * n + i] = temp;
    }
  }
  A = At;
  gettimeofday(&end, NULL);

  // Print the output matrix

  printf("Output Matrix:\n");

  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      printf("%d\t", A[i * n + j]);
    }
    printf("\n");
  }

  free(At);

  printf("\n");
  printf("Time: %.0lf", time_diff(start, end));

}
