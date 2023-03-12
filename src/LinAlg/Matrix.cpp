#include "Matrix.h"

Matrix::Matrix()
   : numRows(3),
     numCols(3)
{
   for (unsigned int i = 0; i < numRows; i++)
   {
      rows.emplace_back(numCols);
   }
}
Matrix::Matrix(unsigned int r, unsigned int c)
   : numRows(r),
     numCols(c)
{
   for (unsigned int i = 0; i < numRows; i++)
   {
      rows.emplace_back(numCols);
   }
}
Matrix::Matrix(std::list<std::list<double>> inList)
{
   for (auto row: inList)
   {
      rows.emplace_back(row);
   }

   numRows = rows.size();
   numCols = rows[0].size;
}
Matrix::Matrix(const Matrix &matIn)
   : rows(matIn.rows),
     numRows(matIn.numRows),
     numCols(matIn.numCols)
{}

Matrix Matrix::operator*(Matrix matIn)
{
   assert(numCols == matIn.numRows);
   Matrix newMat(numRows, matIn.numCols);
   for (unsigned int i = 0; i < numRows; i++)
   {
      for (unsigned int j = 0; j < matIn.numCols; j++)
      {
         newMat.rows[i].vals[j] = Dot(getRow(i), matIn.getColumn(j));
      }
   }

   return newMat;
}
Vector Matrix::operator*(const Vector &vecIn)
{
   assert(numCols == vecIn.size);
   Vector newVec(numCols);
   for (unsigned int i = 0; i < numRows; i++)
   {
      newVec.vals[i] = Dot(getRow(i), vecIn);
   }

   return newVec;
}

Vector Matrix::getRow(unsigned int rowNum)
{
   return rows[rowNum];
}
Vector Matrix::getColumn(unsigned int colNum)
{
   Vector newVec(numRows);
   for (unsigned int i = 0; i < numRows; i++)
   {
      newVec.vals[i] = rows[i].vals[colNum];
   }

   return newVec;
}

void Matrix::print()
{
   std::cout << "[\n" << std::endl;
   for (auto row: rows)
   {
      row.print();
   }
   std::cout << "\n]\n" << std::endl;
}
