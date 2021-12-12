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
//Creates a matrix of rows "r" and columns "c" with all vals set to "val".
matrix_t* matinit(int r, int c, int value);

//***DESTRUCTION FUNCTIONS***//
//Frees up a created matrix.
void matfree(matrix_t* mat);

//***ACCESSOR FUNCTIONS***//
//Prints out a given matrix_t.
//Returns 0 if successful, -1 otherwise.
int matprint(matrix_t* mat);

//***MUTATOR FUNCTIONS***//
//Sums up a given column. (aka all rows that correspond to parameter column)
//Returns 0 if successful, -1 otherwise.
int matsumcol(matrix_t* mat, int c);
//Copies a matrix's value into others. (Currently only works if dims same)
//Returns 0 if successful, -1 otherwise.
int matcpy(matrix_t* dest, matrix_t* src);

//Multiplies two matrices together. Cols of a MUST equal rows of b.
//Creates a matrix with dims (a.rows,b.cols) if successful
//Returns 0 if successful, -1 if parameters not met.
int matmult(matrix_t* dest, matrix_t* a, matrix_t* b);

//Multiplies a matrix by itself 'pow' times to get the exponential of a matrix.
//Returns 0 if successful, -1 if parameters not met.
int matpow(matrix_t* dest, matrix_t* src, int pow);

//Helper function to replace a matrix with another in case we are overwriting.
void matreplace(matrix_t* dest, matrix_t* src);
#endif