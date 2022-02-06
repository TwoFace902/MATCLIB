#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "matrixlib.h"

matrix_t* matinit(int r, int c, int val){
  matrix_t* mat = malloc(sizeof(matrix_t));
  int* seed = calloc(r*c,sizeof(int));
  int** feed = malloc(r*sizeof(int*));

  for(int i = 0; i < r; i++){
    feed[i] = seed + i * c;
  }
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      feed[i][j] = val;
    }
  }
  mat->rows = r;
  mat->cols = c;
  mat->matrix = feed;
  return mat;
}

int matprint(matrix_t* mat){
  for(int i = 0; i < mat->rows; i++){
    for(int j = 0; j < mat->cols; j++){
      printf("%d ", mat->matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  return 0;
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
  if(dest == src){
    return 0;
  }
  matrix_t* mat = matinit(dest->rows,dest->cols,0);
  if(dest->rows < src->rows || dest->cols < src->cols)
    return -1;
  for(int i = 0; i < src->rows; i++){
    for(int j = 0; j < src->cols; j++){
      mat->matrix[i][j] = src->matrix[i][j];
    }
  }
  matfree(dest);
  dest->matrix = mat->matrix;
  return 0;
}

int matmult(matrix_t* dest, matrix_t* a, matrix_t* b){
  if(a->cols != b->rows){
    return -1;
  }
  matrix_t* mat = matinit(a->rows,b->cols,0);
  for (int i = 0; i < a->rows; i++){
    for (int j = 0; j < b->cols; j++){
      int dot = 0;
      for(int s = 0; s < a->cols; s++){
        dot += a->matrix[i][s] * b->matrix[s][j];
      }
      mat->matrix[i][j] = dot;
    }
  }
  matreplace(dest,mat);
  return 0;
}

int matpow(matrix_t* dest, matrix_t* src, int p){
  if(src->rows != src->cols)
    return -1;
  matrix_t* tmp = matinit(src->rows,src->cols,0);
  matcpy(tmp,src);
  matrix_t* mat = matiden(src->rows);
  while (p != 0){
    int curr = p & 1;
    p = p >> 1;
    if(curr){
      matmult(mat,mat,tmp);
    }
    matmult(tmp,tmp,tmp);
  }
  matreplace(dest,mat);
  return 0;
}

void matreplace(matrix_t* dest, matrix_t* src){
  if(dest == src)
    return;
  matfree(dest);
  dest->matrix = src->matrix;
  dest->rows = src->rows;
  dest->cols = src->cols;
}

void matfree(matrix_t* mat){
  free(mat->matrix);
}

int matcpyrow(matrix_t* dest, matrix_t* src, int row, int start){
  if(dest->cols < src->cols + start){
    return -1;
  }
  for(int i = start; i < src->cols; i++){
    dest->matrix[row][i] = src->matrix[row][i];
  }
  return 0;
}

int matcpycol(matrix_t* dest, matrix_t* src, int col, int start){
  if(dest->rows < src->rows + start){
    return -1;
  }
  for(int i = start; i < src->rows; i++){
    dest->matrix[i][col] = src->matrix[i][col];
  }
  return 0;
}

int mattranspose(matrix_t* dest, matrix_t* src){
   for (int j = 0; j < src->cols; j++){
      for(int i = 0; i < src->rows; i++){
         dest->matrix[i][j] = src->matrix[j][i];
      }
   }
   return 0;
}
