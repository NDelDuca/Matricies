#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


// gets time in seconds + microseconds
long getTime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int powerOf2(int block_size){

  if (block_size == 0){
    return 0;
  }
  while (block_size != 1)
  {
      if (block_size % 2 != 0){
        printf("%s\n", "Error, block size is not a power of 2.");
        exit(0);
       }
      block_size = block_size/2;
  }
  return 0;
}

void main(int argc, char const *argv[]){

  long start, end;

  int i, j;
  char *p;

  // take in args
  int row = strtol(argv[1], &p, 10);
  int col = strtol(argv[2], &p, 10);
  int block = strtol(argv[3], &p, 10);

  powerOf2(block);

  int n = row + col;

  // allocate for arrays
  float *A = malloc(block * sizeof(float));
  float *At = malloc(block * sizeof(float));

  // Build the matrix
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      A[i * n + j] = rand();
    }
  }

  start = getTime();

  // Transpose the matrix
  for(i = 0; i < row; i += block){
    for(j = 0; j < col; j += block){
      for(row = i; row < i + block; ++row){
          for(col = j; col < j + block; ++col){
            At[col * n + row] = A[row * n + col];
          }
        }
      }
    }

  end = getTime();

  printf("\nTime: %.0lf microseconds", (end - start));

  free(A);
  free(At);

}
