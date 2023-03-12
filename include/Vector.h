#ifndef VECTOR_H
#define VECTOR_H

#include <sstream>
#include <iostream>
#include <vector>
#include <list>
#include <math.h>

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

   void sizeCheck(const Vector &vecIn);
 //  void sizeCheck(const Matrix &matIn);

   void print();

   std::vector<double> vals;
   unsigned int size;

};

double Dot(Vector v1, Vector v2);
Vector Cross(Vector v1, Vector v2);
double Mag(Vector vIn);
Vector Norm(Vector vIn);
#endif
