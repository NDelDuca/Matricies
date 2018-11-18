#include <stdio.h>
#include <stdlib.h>

void main(int argc, char const *argv[]){

  int i;
  int j;
  char *p;

  int matrix[][];


  // set row = to the width of the matrix
  int row = strtol(argv[1], &p, 10);

  // square matricies only, so col = row
  int col = row;

  //int matrix [malloc(row * sizeof(float))][malloc(col * sizeof(float))];

  // build the matrix
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      matrix[i][j] = 1;
    }
  }

  // transpose the matrix
  for(i = 0; i < row; i++){
    for(j = 0; j < col; j++){
      matrix[i][j] = 1;
    }
  }

}
