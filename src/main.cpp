#include <iostream>
#include "sloppyMath.h"

void runVectorTests()
{
   std::cout << "---- Vector Tests ----" << std::endl;
   Vector vec1({1,2,3});
   Vector vec2({2,3,1});
   Vector vec3;

   std::cout << "Vector 1: ";
   vec1.print();
   std::cout << "\nVector 2: ";
   vec2.print();

   std::cout << "\nV3 = V1:" << std::endl;
   vec3 = vec1;
   std::cout << "V3: ";
   vec3.print();

   std::cout << "\nV1 += 2" << std::endl;
   std::cout << "V1: ";
   (vec1+2.0).print();

   std::cout << "\nV1 -= 2" << std::endl;
   std::cout << "V1: ";
   (vec1-2.0).print();

   std::cout << "\nV1 *= 2" << std::endl;
   std::cout << "V1: ";
   (vec1*2.0).print();

   std::cout << "\nV1 DOT V2" << std::endl;
   std::cout << "V1*V2: ";
   std::cout << Dot(vec1, vec2) << std::endl;

   std::cout << "\nV1 CROSS V2" << std::endl;
   std::cout << "V1XV2: ";
   Cross(vec1, vec2).print();

   std::cout << "\nV1 /= 2" << std::endl;
   std::cout << "V1: ";
   (vec1/2.0).print();

   std::cout << "\n|V1|" << std::endl;
   std::cout << "|V1|: " << Mag(vec1) << std::endl;

   std::cout << "\nuV1" << std::endl;
   std::cout << "uV1: ";
   (Norm(vec1)).print();
}
void runMatrixTests()
{
   std::cout << "\n---- Matrix Tests ----" << std::endl;
   Vector v1({2,3,4});
   Matrix m1({{1,2,3}, {2,3,2}, {3,1,2}});
   Matrix m2({{0,1,0}, {0,0,1}, {1,0,1}});

   std::cout << "Vector1: ";
   v1.print();
   std::cout << "Matrix1: ";
   m1.print();
   std::cout << "Matrix2: ";
   m2.print();

   std::cout << "M1*M2" << std::endl;
   (m1*m2).print();

   std::cout << "M2*M1" << std::endl;
   (m2*m1).print();

   std::cout << "V1*M1" << std::endl;
   (v1*m1).print();

   std::cout << "\nM1*V1" << std::endl;
   (m1*v1).print();
}

int main()
{
   // Vector Tests
   runVectorTests();

   // Matrix Tests
   runMatrixTests();

   return 0;
}

