#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h"

struct Matrix
{
   Matrix(unsigned int r, unsigned int c);
   Matrix(const Matrix &matIn);

   Matrix operator*(const Matrix &matIn);
   Vector operator*(const Vector &vecIn);
   Vector getRow(unsigned int rowNumt);
   Vector getColumn(unsigned int colNum);

   std::vector<Vector> vals;
   unsigned int numRows, numCols;

};
#endif
