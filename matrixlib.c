#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "matrixlib.h"

matrix_t* matinit(int r, int c){
  matrix_t* mat = malloc(sizeof(matrix_t));
  int* seed = calloc(r*c,sizeof(int));
  int** feed = malloc(r*sizeof(int*));

  for(int i = 0; i < r; i++){
    feed[i] = seed + i * c;
  }
  mat->rows = r;
  mat->cols = c;
  mat->matrix = feed;
  return mat;
}

matrix_t* matones(int r, int c){
  matrix_t* mat = malloc(sizeof(matrix_t));
  int* seed = calloc(r*c,sizeof(int));
  int** feed = malloc(r*sizeof(int*));

  for(int i = 0; i < r; i++){
    feed[i] = seed + i * c;
  }
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      feed[i][j] = 1;
    }
  }
  mat->rows = r;
  mat->cols = c;
  mat->matrix = feed;
  return mat;
}
void matfree(matrix_t* mat){
  free(mat->matrix);
}

int matprint(matrix_t* mat){
  for(int i = 0; i < mat->rows; i++){
    for(int j = 0; j < mat->cols; j++){
      printf("%d ", mat->matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return 1;
}

matrix_t* matiden(int s){
  matrix_t* mat = malloc(sizeof(matrix_t));
  int* seed = calloc(s*s,sizeof(int));
  int** feed = malloc(s*sizeof(int*));

  for(int i = 0; i < s; i++){
    feed[i] = seed + i * s;
    feed[i][i] = 1;
  }
  mat->rows = s;
  mat->cols = s;
  mat->matrix = feed;
  return mat;
}

int matcpy(matrix_t* dest, matrix_t* src){
  matrix_t* mat = matinit(dest->rows,dest->cols);
  if(dest->rows < src->rows || dest->cols < src->cols)
    return -1;
  for(int i = 0; i < src->rows; i++){
    for(int j = 0; j < src->cols; j++){
      mat->matrix[i][j] = src->matrix[i][j];
    }
  }
  matfree(dest);
  dest->matrix = mat->matrix;
  return 1;
}