#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


// gets time in seconds + microseconds
long getTime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

void main(int argc, char const *argv[]){

  long start, end;

  int i, j, row, col;
  char *p;

  // take in args
  int n = strtol(argv[1], &p, 10);
  int block = strtol(argv[2], &p, 10);

  // allocate for arrays
  float *A = malloc(block * sizeof(float));
  float *At = malloc(block * sizeof(float));

  // Build the matrix
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      A[i * n + j] = rand();
    }
  }

  //printf("%f\n", A[8]);

  // Print the input matrix

  /*
  printf("Input Matrix:\n");

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%f\t", A[i * n + j]);
    }
    printf("\n");
  }
  printf("\n");

  */

  //printf("%f\n", A[8]);

  // Transpose the matrix
  start = getTime();

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

  end = getTime();

  // Print the output matrix

  /*
  printf("Output Matrix:\n");

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%f\t", At[i * n + j]);
    }
    printf("\n");
  }

  */

  printf("\nTime: %.0lf microseconds", (end - start));

  free(At);

}
