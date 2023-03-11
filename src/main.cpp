#include <iostream>
#include "sloppyMath.h"

int main()
{
   // Vector Tests
   std::list<double> l1{1.0,2.0,3.0,4.0,5.0};
   std::list<double> l2{5.0,4.0,3.0,2.0,1.0};
   Vector vec1(l1);
   Vector vec2(l2);
   Vector vec3;

   vec3 = vec1;
   vec3.print();

   (vec1+2.0).print();
   (vec2+2.0).print();
   (vec1-2.0).print();
   (vec2-2.0).print();
   (vec1*2.0).print();
   (vec2*2.0).print();
   std::cout << vec3.dot(vec1, vec2) << std::endl;
   (vec1/2.0).print();
   (vec2/2.0).print();
   (vec1.normalize());
   (vec2.normalize());
   vec1.print();
   vec2.print();


   std::cout << "Hello, LIB!" << std::endl;
   return 0;
}
