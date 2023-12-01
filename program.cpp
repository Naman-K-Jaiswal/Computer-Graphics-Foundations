#include <iostream>
#include "Vector3.h"

using namespace std;

int main() 
{
    float a,b,c,d,e,f;
    cout <<"Enter two vectors.";
    cin>>a>>b>>c>>d>>e>>f;
     Vector3 v1(a,b,c),v2(d,e,f);

    double h=v1.dotproduct(v1,v2)/((v2.modulus(v2))*(v2.modulus(v2)));

    Vector3 v3(h*v2.x,h*v2.y,h*v2.z);

    cout<<"Component of vector "<< v1.x <<" "<<v1.y<<" "<<v1.z<<" along vector "<<v2.x<<" "<<v2.y<<" "<<v2.z<<" is\n ";
    cout <<v3.x<<" "<<v3.y<<" "<<v3.z<<" \n";

    Vector3 v4(v1.x-v3.x,v1.y-v3.y,v1.z-v3.z);

    cout<<"Component of vector "<<v1.x<<" "<<v1.y<<" "<<v1.z<<" perpendicular to vector "<<v2.x<<" "<<v2.y<<" "<<v2.z<<" is\n ";
    cout <<v4.x<<" "<<v4.y<<" "<<v4.z;
}


