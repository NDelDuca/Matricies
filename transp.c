#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

float time_diff(struct timeval st, struct timeval ed){

  float st_ms, ed_ms, diff;

  st_ms = (float)st.tv_sec*1000000 + (float)st.tv_usec;
  ed_ms = (float)ed.tv_sec*1000000 + (float)ed.tv_usec;

  diff = (float)ed_ms - (float)st_ms;

  return diff;
}

void main(int argc, char const *argv[]){

  struct timeval start, end;

  int i, j, row, col;
  char *p;

  int n = strtol(argv[1], &p, 10);
  int block = strtol(argv[2], &p, 10);

  float *A = malloc(block * sizeof(float));
  float *At = malloc(block * sizeof(float));

  // Build the matrix
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      A[i * n + j] = rand();
    }
  }

  printf("%f\n", A[8]);

  // Print the input matrix
  printf("Input Matrix:\n");

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%f\t", A[i * n + j]);
    }
    printf("\n");
  }
  printf("\n");

  // Transpose the matrix
  gettimeofday(&start, NULL);

  //printf("%f\n", A[8]);

  for(i = 0; i < n; i += block){
    for(j = 0; j < n; j += block){
      for(row = i; row < i + block; ++row){
          for(col = j; col < j + block; ++col){

            // Last element is 0, makes no sense, since it IS hitting A[8] and before this loop A[8] != 0
            At[col * n + row] = A[row * n + col];
          }
        }
      }
    }

/*
  Old iteration, didn't use block size
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      At[i * n + j] = A[j * n + i];
    }
  }

*/

  gettimeofday(&end, NULL);

  // Print the output matrix
  printf("Output Matrix:\n");

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%f\t", At[i * n + j]);
    }
    printf("\n");
  }

  printf("\nTime: %.0lf microseconds", time_diff(start, end));

  free(At);

}
