#ifndef VECTOR_H
#define VECTOR_H

#include <sstream>
#include <iostream>
#include <vector>
#include <list>

struct Matrix;
struct Vector
{
   Vector();
   Vector(unsigned int in);
   Vector(std::list<double> inList);
   Vector(const Vector &vecIn);

   void operator=(const Vector &vecIn);

   Vector operator+(double in);
   Vector operator+(const Vector &vecIn);

   Vector operator-(double in);
   Vector operator-(const Vector &vecIn);

   Vector operator*(double in);
//   Vector operator*(const Matrix &matIn);
   double dot(Vector in1, Vector in2);
   Vector cross(Vector in1, Vector in2);

   Vector operator/(double in);
   void normalize();
   Vector normalize(Vector vecIn);
   double magnitude(const Vector &vecIn);

   void sizeCheck(const Vector &vecIn);
 //  void sizeCheck(const Matrix &matIn);

   void print();

   std::vector<double> vals;
   unsigned int size;

};
#endif
