#include <cmath>
using namespace std;
class Vector3{
    public:
    double x,y,z;
};
Vector3 add(Vector3 v1, Vector3 v2){
    Vector3 v;
    v.x=v1.x+v2.x;
    v.y=v1.y+v2.y;
    v.z=v1.z+v2.z;
    return v;
}
    //adds 2 vectors and returns sum
Vector3 subtract(Vector3 v1, Vector3 v2){
        Vector3 v;
        v.x=v1.x-v2.x;
        v.y=v1.y-v2.y;
        v.z=v1.z-v2.z;
        return v;
}
//returns vector v1-v2
Vector3 scalarmul(Vector3 v, double a){
    Vector3 vf;
    vf.x=a*v.x;
    vf.y=a*v.y;
    vf.z=a*v.z;
    return vf;
}
//multiplies vector by scalar
Vector3 scaledown(Vector3 v, double a){
    return scalarmul(v,1/a);
}
//divides original vector by a scalar
Vector3 reverse(Vector3 v){
    Vector3 V;
    V.x=-v.x;
    V.y=-v.y;
    V.z=-v.z;
    return V;
}
//reverses dirn of vector
Vector3 cross(Vector3 v1,Vector3 v2){
    Vector3 V;
    V.x=v1.y*v2.z-v1.z*v2.y;
    V.y=v1.z*v2.x-v1.x*v2.z;
    V.z=v1.x*v2.y-v1.y*v2.x;
    return V;
}
//changes original vector to (original vector X vector v)
double dot(Vector3 v1,Vector3 v2){
    return (v1.x*v2.x)+(v1.y*v2.y)+(v1.z*v2.z);
}
//returns dot product of original vector with a given vector
double mod(Vector3 v){
    return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}
inline Vector3 unit(Vector3 v){
    Vector3 vcap;
    vcap=scaledown(v,mod(v));
    return vcap;
}
double xcomp(Vector3 v){
    return v.x;
}
double ycomp(Vector3 v){
    return v.y;
}
double zcomp(Vector3 v){
    return v.z;
}
double scalartripleprod(Vector3 v1,Vector3 v2, Vector3 v3){
    //return v1.x*(v2.y*v3.z-v2.z*v3.y)-v1.y*(v2.x*v3.z-v2.z*v3.x)+v1.z*(v2.x*v3.y-v2.y*v3.x);
    return(dot(v1,cross(v2,v3)));
}
Vector3 vectortriple(Vector3 v1, Vector3 v2, Vector3 v3){
    return cross(v1,cross(v2,v3));
}
double volume(Vector3 v1, Vector3 v2, Vector3 v3){
    return abs(scalartripleprod(v1,v2,v3));
}
double area(Vector3 v1, Vector3 v2){
    return 0.5*mod(cross(v1,v2));
}
Vector3 operator-(Vector3 v){
    return reverse(v);
}
Vector3 operator-(Vector3 v1,Vector3 v2){
    return subtract(v1,v2);
}
Vector3 operator+(Vector3 v1, Vector3 v2){
    return add(v1,v2);
}
Vector3 operator*(Vector3 v1, Vector3 v2){
    return cross(v1,v2);
}
Vector3 operator*(double a, Vector3 v){
    return scalarmul(v,a);
}
#include <iostream>
using namespace std;
int main(){
    Vector3 v,V;
    cout << "Enter components of vector whose components are to be found\n";
    cout << "Enter x component\n";
    cin >> v.x;
    cout << "Enter y component\n";
    cin >> v.y;
    cout << "Enter z component\n";
    cin >> v.z;
    cout << "Enter components of other vector\n";
    cout << "Enter x component\n";
    cin >> V.x;
    cout << "Enter y component\n";
    cin >> V.y;
    cout << "Enter z component\n";
    cin >> V.z;
    cout << "Component of v along V = "<< dot(v,unit(V))<< endl;
    cout << "Component of v perpendicular to V = "<< sqrt(mod(v)*mod(v)-dot(v,unit(V))*dot(v,unit(V)));
    return 0;
}