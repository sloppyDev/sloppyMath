#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h"

struct Matrix
{
   Matrix(unsigned int r, unsigned int c);
   Matrix(std::list<std::list<double>> inList);
   Matrix(const Matrix &matIn);

   Matrix operator*(const Matrix &matIn);
   Vector operator*(const Vector &vecIn);

   Vector getRow(unsigned int rowNum);
   Vector getColumn(unsigned int colNum);

   std::vector<Vector> rows;
   unsigned int numRows, numCols;
};
#endif
