#ifndef EULER_ANGLES_H
#define EULER_ANGLES_H

#include "Vector.h"

struct Quaternion;
struct TransformMat;

struct EulerAngles : Vector
{
   EulerAngles();
   EulerAngles(double roll, double pitch, double yaw);
   EulerAngles(const EulerAngles &eaIn);
   EulerAngles(const Quaternion &quatIn);
   EulerAngles(const TransformMat &matIn);

   Quaternion getQuat();

   double getRoll();
   double getPitch();
   double getYaw();
};
#endif
