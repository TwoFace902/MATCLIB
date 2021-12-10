#ifndef MATLIB_H
#define MATLIB_H

typedef struct Matrix{
  int** matrix;
  int rows;
  int cols;
} matrix_t;

//***CREATION FUNCTIONS***//
//Creates identity matrix of size 's'.
matrix_t* matiden(int s);
//Creates a matrix of rows "r" and columns "c".
matrix_t* matinit(int r, int c);
//Creates a matrix of rows "r" and columns "c" of all 1s.
matrix_t* matones(int r, int c);

//***DESTRUCTION FUNCTIONS***//
//Frees up a created matrix.
void matfree(matrix_t* mat);

//***ACCESSOR FUNCTIONS***//
//Prints out a given matrix_t.
//Returns 1 if successful, 0 otherwise.
int matprint(matrix_t* mat);

//***MUTATOR FUNCTIONS***//
//Sums up a given column. (aka all rows that correspond to parameter column)
//Returns 1 if successful, 0 otherwise.
int matsumcol(matrix_t* mat, int c);
//Copies a matrix's value into others. (Currently only works if dims same)
//Returns 1 if successful, 0 otherwise.
int matcpy(matrix_t* dest, matrix_t* src);

#endif