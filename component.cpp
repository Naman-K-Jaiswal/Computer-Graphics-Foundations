#include <iostream>
#include<cmath>
#include "C:\Users\Mohit Choudhary\Desktop\gamedev\assignment1\Computer-Graphics-Foundations\assignment1.h"
#include "assignment1.h"
using namespace std;

int main(){
    float a,b,c,d,e,f;
    Vector3 vector1(a,b,c), vector2(d,e,f);
    cout<<"enter xyz components of the two vectors:"<<endl;
    cin >> a >> b >> c >> d >> e >> f;
    
   float m= vector1.dotproduct(vector1,vector2)/((vector1.mod(vector2))*vector1.mod(vector2));

   Vector3 vector4(d*m , e*m , f*m);

   cout<< "component of vector1 along vector2 is:" << vector4.x << vector4.y <<vector4.z << endl;

   Vector3 vector5(a-(d*m) , b-(e*m) , c-(f*m));

   cout<<"component of vector v1 perpendicular to v2 is:" << vector5.x << vector5.y << vector5.z <<endl;

   return 0;
}