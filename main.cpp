#include "vector3.h"
#include<iostream>

using namespace std;

int main(){
    Vector3 v1 = Vector3(2, 3, 5);
    Vector3 v2 = Vector3(3, 4, 5);

    Vector3 v3 = vec_along(v1, v2);
    Vector3 v4 = vec_perp(v1, v2);

    cout<< "component of vector v1 along v2 : ";
    v3.print();
    cout<< "component of vector v1 perpendicular to v2 : " ;
    v4.print();

    
}



