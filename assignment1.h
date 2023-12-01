#include <iostream>
#include <cmath>
using namespace std;

class Vector3{
   public:
     float x,y,z;

   Vector3(float xcom,  float ycom , float zcom){
    x = xcom;
    y = ycom;
    z = zcom;
   }

   Vector3 add(Vector3 vec1 , Vector3 vec2){
    float a;
    float b;
    float c;
    Vector3 vec3(a,b,c);

    vec3.x = vec1.x + vec2.x;
    vec3.y = vec1.y + vec2.y;
    vec3.z = vec1.z + vec2.z;
    return vec3;

   }
    Vector3 subtract(Vector3 vec1 , Vector3 vec2){
    float a;
    float b;
    float c;
    Vector3 vec3(a,b,c);

    vec3.x = vec1.x - vec2.x;
    vec3.y = vec1.y - vec2.y;
    vec3.z = vec1.z - vec2.z;
    return vec3;

   }

   Vector3 scalarmultiplication(Vector3 vec1 , float scalar){
    vec1.x = (vec1.x)*scalar;
    vec1.y = (vec1.y)*scalar;
    vec1.z = (vec1.z)*scalar;
    return vec1;
   }
  
   Vector3 scaledown(Vector3 vec1 , float scalar){
    vec1.x = (vec1.x)/scalar;
    vec1.y = (vec1.y)/scalar;
    vec1.z = (vec1.z)/scalar;
    return vec1;
   }
   Vector3 reversedirection(Vector3 vec1){
    vec1.x = (vec1.x)*(-1);
    vec1.y = (vec1.y)*(-1);
    vec1.z = (vec1.z)*(-1);
   }
   Vector3 crossproduct(Vector3 vec1 , Vector3 vec2){
    float a;
    float b;
    float c;
    Vector3 vec3(a,b,c);
   vec3.x = (vec1.y)*(vec2.z) - (vec1.z)*(vec2.y);
   vec3.y = (vec1.z)*(vec2.x) - (vec1.x)*(vec2.z);
   vec3.z = (vec1.x)*(vec2.y) - (vec1.y)*(vec2.x);

   return vec3;
   }

   float dotproduct(Vector3 vec1 , Vector3 vec2){
    float ans;
    ans = (vec1.x)*(vec2.x) + (vec1.y)*(vec2.y) + (vec1.z)*(vec2.z);
    return ans;
   }

   float mod(Vector3 vec1){
     float modulus;
     modulus = sqrt((vec1.x)*(vec1.x)+(vec1.y)*(vec1.y)+(vec1.z)*(vec1.z));
     return modulus;
   }
   
   Vector3 unit(Vector3 vec1){
    float modulus = mod(vec1);
    vec1.x = (vec1.x)/modulus;
    vec1.y = (vec1.y)/modulus;
    vec1.z = (vec1.z)/modulus;
    return vec1;
   }

   float xcomponent(Vector3 vec1){
    return vec1.x ; 
   }
   float ycomponent(Vector3 vec1){
    return vec1.y ; 
   }
   float zcomponent(Vector3 vec1){
    return vec1.z ; 
   }

   float scalartripleproduct(Vector3 vec1 ,Vector3 vec2 ,Vector3 vec3){
    float a;
    float b;
    float c;
    Vector3 vec4(a,b,c);

    vec4 = crossproduct(vec2 , vec3);
    float stp;
    stp = dotproduct(vec4 , vec1);
    return stp;
   }

   Vector3 vectortripleproduct(Vector3 vec1 ,Vector3 vec2 ,Vector3 vec3){
    float a;
    float b;
    float c;
    Vector3 vec4(a,b,c);

    vec4 = crossproduct(vec2 , vec3);

    return crossproduct(vec1 , vec4);
  }
  
   


};
  class parallelopiped : public Vector3{
    Vector3 v1,v2,v3;

    parallelopiped(Vector3 vect1 , Vector3 vect2 , Vector3 vect3):Vector3(vect1),v1(vect1), v2(vect2), v3(vect3){
      
    }


    float volume(Vector3 v1 , Vector3 v2 , Vector3 v3){
      return abs(scalartripleproduct(v1 , v2 , v3));
    }

  };
  
  class triangle : public Vector3{
    Vector3 v1,v2;

    triangle(Vector3 vect1 , Vector3 vect2): Vector3(vect1) , v1(vect1) , v2(vect2) {
      
    }
    float area(Vector3 v1 , Vector3 v2){
      return 0.5*(mod(crossproduct(v1,v2)));
    }
  };

 Vector3 operator+ (Vector3 v1 , Vector3  v2){
      return v1.add(v1,v2);
 }
 Vector3 operator- (Vector3 v1, Vector3 v2){
     return v1.subtract(v1,v2);
 }
 float operator* (Vector3 v1, Vector3 v2){
     return v1.dotproduct(v1,v2);
 }
 Vector3 operatorx (Vector3 v1, Vector3 v2){
     return v1.crossproduct(v1,v2);
 }
 Vector3 operator% (Vector3 v1 , float scalar){
    return v1.scalarmultiplication(v1,scalar);
 }
