#include <cassert>
#include <math.h>

#include "Vector.h"
#include "Matrix.h"

Vector::Vector()
   : size(3)
{
   vals.push_back(0.0);
   vals.push_back(0.0);
   vals.push_back(0.0);
}

Vector::Vector(unsigned int in)
   : size(in)
{
   for (unsigned int i = 0; i < in; i++)
   {
      vals.push_back(0.0);
   }
}
Vector::Vector(std::list<double> inList)
   : size(inList.size())
{
   for (double a: inList)
   {
      vals.push_back(a);
   }
}

Vector::Vector(const Vector &vecIn)
   : size(vecIn.size)
{
   vals = vecIn.vals;
}

void Vector::operator=(const Vector &vecIn)
{
   size = vecIn.size;
   vals = vecIn.vals;
}

Vector Vector::operator+(double in)
{
   Vector newVec(*this);
   for (unsigned int i = 0; i < size; i++)
   {
      newVec.vals[i] += in;
   }

   return newVec;
}

Vector Vector::operator+(const Vector &vecIn)
{
   sizeCheck(vecIn);
   Vector newVec(*this);
   for (unsigned int i = 0; i < size; i++)
   {
      newVec.vals[i] += vecIn.vals[i];
   }

   return newVec;
}

Vector Vector::operator-(double in)
{
   Vector newVec(*this);
   for (unsigned int i = 0; i < size; i++)
   {
      newVec.vals[i] -= in;
   }

   return newVec;
}
Vector Vector::operator-(const Vector &vecIn)
{
   sizeCheck(vecIn);
   Vector newVec(*this);
   for (unsigned int i = 0; i < size; i++)
   {
      newVec.vals[i] -= vecIn.vals[i];
   }

   return newVec;
}

Vector Vector::operator*(double in)
{
   Vector newVec(*this);
   for (unsigned int i = 0; i < size; i++)
   {
      newVec.vals[i] *= in;
   }

   return newVec;
}
//Vector Vector::operator*(const Matrix &matIn)
//{
//   sizeCheck(matIn);
//   Vector newVec(matIn.numCols);
//   for (unsigned int i = 0; i < newVec.size; i++)
//   {
//      newVec.vals[i] = dot(*this, matIn.getColumn(i));
//   }
//
//   return newVec;
//}
double Vector::dot(Vector in1, Vector in2)
{
   assert(in1.size==in2.size);

   double dot = 0.0;
   for (unsigned int i = 0; i < size; i++)
   {
      dot += in1.vals[i]*in2.vals[i];
   }

   return dot;
}
Vector Vector::cross(Vector in1, Vector in2)
{
   assert(in1.size==3); // Cross Product Only Works in 3D dummy
   assert(in1.size==in2.size);

   Vector newVec(3);
   newVec.vals[0] = in1.vals[1]*in2.vals[2] - in1.vals[2]*in2.vals[1];
   newVec.vals[1] = in1.vals[2]*in2.vals[0] - in1.vals[0]*in2.vals[2];
   newVec.vals[2] = in1.vals[0]*in2.vals[1] - in1.vals[1]*in2.vals[0];

   return newVec;
}

Vector Vector::operator/(double in)
{
   Vector newVec(*this);
   for (unsigned int i = 0; i < size; i++)
   {
      newVec.vals[i] /= in;
   }

   return newVec;
}
void Vector::normalize()
{
   *this = *this/magnitude(*this);
}
Vector Vector::normalize(Vector vecIn)
{
   return vecIn/magnitude(vecIn);
}
double Vector::magnitude(const Vector &vecIn)
{
   double squareSum = 0.0;
   for (unsigned int i = 0; i < vecIn.size; i++)
   {
      squareSum += vecIn.vals[i]*vecIn.vals[i];
   }
   return sqrt(squareSum);
}

void Vector::sizeCheck(const Vector &vecIn)
{
   assert(size == vecIn.size);
}
//void Vector::sizeCheck(const Matrix &matIn)
//{
//   assert(size == matIn.numRows);
//}

void Vector::print()
{
   std::stringstream ss;
   ss << "[";
   for (unsigned int i = 0; i < size-1; i++)
   {
      ss << vals[i] << ", ";
   }
   ss << vals[size-1] << "]";

   std::cout << ss.str() << std::endl;
}

//double Dot(Vector v1, Vector v2)
//{
//   assert(v1.size == v2.size);
//   double vsum = 0.0;
//   for (unsigned int i = 0; i < v1.size; i++)
//   {
//      vsum += v1.vals[i]*v2.vals[i];
//   }
//
//   return vsum;
//}
//
//Vector Cross(Vector v1, Vector v2)
//{
//   assert(v1.size==3); // Cross Product Only Works in 3D dummy
//   assert(v1.size==v2.size);
//
//   Vector newVec(3);
//   newVec.vals[0] = v1.vals[1]*v2.vals[2] - v1.vals[2]*v2.vals[1];
//   newVec.vals[1] = v1.vals[2]*v2.vals[0] - v1.vals[0]*v2.vals[2];
//   newVec.vals[2] = v1.vals[0]*v2.vals[1] - v1.vals[1]*v2.vals[0];
//
//   return newVec;
//}
//
//double Mag(Vector vIn)
//{
//   double sqsum = 0.0;
//   for (unsigned int i = 0; i < vIn.size; i++)
//   {
//      sqsum += vIn.vals[i]*vIn.vals[i];
//   }
//
//   return sqrt(sqsum);
//}
