#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <cmath>

class Vector3
{
 public:
 float x;
 float y;
 float z;

 Vector3(float xcomp,float ycomp,float zcomp)
 {
  x=xcomp;
  y=ycomp;
  z=zcomp;
 }
  double modulus(Vector3 vect)
  {
    return sqrt(vect.x*vect.x+vect.y*vect.y+vect.z*vect.z);
  }

  Vector3 sum(Vector3 vect1,Vector3 vect2)
  {
   
    Vector3 sum(vect1.x+vect2.x,vect1.y+vect2.y,vect1.z+vect2.z);
    return sum;
  }
  Vector3 subtract(Vector3 vect1,Vector3 vect2)
  {
    Vector3 def(vect1.x+vect2.x,vect1.y+vect2.y,vect1.z+vect2.z);
    return def;
  }
  Vector3 mulscalar(int a,Vector3 vect)
  {
    Vector3 ans(a*vect.x,a*vect.y,a*vect.z);
    return ans;
  }
   Vector3 scaledown(int a,Vector3 vect)
  {
    Vector3 ans(a*vect.x,a*vect.y,a*vect.z);
    return ans;
  }
   Vector3 reverse(Vector3 vect)
  {
    float x1,y1,z1;
    Vector3 ans(x1,y1,z1);
    ans.x=0-vect.x;
    ans.y=0-vect.y;
    ans.z=0-vect.z;
    return ans;
  }
   Vector3 crossproduct(Vector3 vect1,Vector3 vect2)
  {
    Vector3 ans(vect1.y*vect2.z-vect2.y*vect1.z,vect1.z*vect2.x-vect2.z*vect1.x,vect1.x*vect2.y-vect2.x*vect1.y);
    return ans;
  }
  double dotproduct(Vector3 vect1,Vector3 vect2)
  {
   return vect1.x*vect2.x+vect1.y*vect2.y+vect1.z*vect2.z;
  }
  Vector3 unitvec(Vector3 vect)
  {
    float x1,y1,z1,a;
    Vector3 ans(x1,y1,z1);
    a=sqrt(x*x+y*y+z*z);
    ans.x=a*vect.x;
    ans.y=a*vect.y;
    ans.z=a*vect.z;
    return ans;
  }
   float xcomp(Vector3 vect)
   {
    return vect.x;
   }
   float ycomp(Vector3 vect)
   {
    return vect.y;
   }
   float zcomp(Vector3 vect)
   {
    return vect.z;
   }
   double scalartripleproduct(Vector3 vect1,Vector3 vect2,Vector3 vect3)
   {
    return (vect3.x*crossproduct(vect1,vect2).x+vect3.y*crossproduct(vect1,vect2).y+vect3.z*crossproduct(vect1,vect2).z);
   }
   Vector3 vectortripleproduct(Vector3 vect1,Vector3 vect2,Vector3 vect3)
   {
    Vector3 ans(subtract(mulscalar(dotproduct(vect1,vect3),vect2),mulscalar(dotproduct(vect1,vect2),vect3)).x,subtract(mulscalar(dotproduct(vect1,vect3),vect2),mulscalar(dotproduct(vect1,vect2),vect3)).y,subtract(mulscalar(dotproduct(vect1,vect3),vect2),mulscalar(dotproduct(vect1,vect2),vect3)).z);
    return ans;
   }
};

class Parallelopiped : public Vector3
{
    public:
    Vector3 v1,v2,v3;

    Parallelopiped(Vector3 vect1,Vector3 vect2,Vector3 vect3) :Vector3(vect1),v1(vect1),v2(vect2),v3(vect3)
    {
    }
    double volume(Vector3 v1,Vector3 v2,Vector3 v3)
    {
        return abs(scalartripleproduct(v1,v2,v3));
    }
};
class Triangle : public Vector3
{
    public:
    Vector3 v1,v2;

    Triangle(Vector3 vect1,Vector3 vect2) :Vector3(vect1),v1(vect1),v2(vect2)
    {}
    double area(Vector3 v1,Vector3 v2)
    {
        return 0.5*modulus(crossproduct(v1,v2));
    }
};

Vector3 operator+(Vector3 v1,Vector3 v2)
{
    return v1.sum(v1,v2);
}
Vector3 operator-(Vector3 v1,Vector3 v2)
{
    return v1.subtract(v1,v2);
}
double operator*(Vector3 v1,Vector3 v2)
{
    return v1.dotproduct(v1,v2);
}
Vector3 operator%(Vector3 v1,Vector3 v2)
{
    return v1.crossproduct(v1,v2);
}
Vector3 operator/(int a,Vector3 v2)
{
    return v2.mulscalar(a,v2);
}

#endif