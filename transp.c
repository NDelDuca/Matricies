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

  int n = strtol(argv[1], &p, 10);

  double *A = malloc(n * sizeof(float));
  double *At = malloc(n * sizeof(float));

  // build the matrix
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      A[i * n + j] = rand();
    }
  }


  // Print the input matrix

  printf("Input Matrix:\n");

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d\t", A[i * n + j]);
    }
    printf("\n");
  }
  printf("\n");



  // transpose the matrix
  gettimeofday(&start, NULL);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      At[i * n + j] = A[j * n + i];
    }
  }
  A = At;
  gettimeofday(&end, NULL);

  // Print the output matrix

  printf("Output Matrix:\n");

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d\t", A[i * n + j]);
    }
    printf("\n");
  }

  free(At);

  printf("Time: %.0lf", time_diff(start, end));

}
