#include<cmath>
#include<iostream>

class Vector3{

public:

    float x;
    float y;
    float z;

    Vector3(float a, float b, float c){
        this->x=a;
        this->y=b;
        this->z=c;
    }

    //reverse vector
    void operator-- (int a){

        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;

    }

    void operator-- (){

        this->x = -this->x;
        this->y = -this->y;
        this->z = -this->z;

    }



    //add
    Vector3 operator + (Vector3 const& v){
        Vector3 res = Vector3(v.x + this->x,v.y + this->y, v.z + this->z );
        return res;

    }

    //subtract
    Vector3 operator - (Vector3 const& v){
        Vector3 res = Vector3(-v.x + this->x,-v.y + this->y, -v.z + this->z );
        return res;

    }

    //multiply with scalar
    Vector3 operator < (float const& t){
        Vector3 res = Vector3(this->x * t,this->y * t, this->z * t );
        return res;
    }
    //cross
    Vector3 operator ^ (Vector3 const& v){
        Vector3 res = Vector3(-v.y*this->z + this->y * v.z, -v.z*this->x + this->z * v.x, -v.x*this->y + this->x * v.y);
        return res;
    }

    //dot
    float operator * (Vector3 const& v){
        return this->x * v.x + this->y * v.y + this->z * v.z;

    }

    Vector3 add(Vector3 v1){
        float p = v1.x + this->x;
        float q= v1.y + this->y;
        float r= v1.z + this->z;
        Vector3 res = Vector3(p, q, r);

        return res;

    }

    Vector3 subtract(Vector3 v1, Vector3 v2){
        int p = v1.x - this->x;
        int q= v1.y - this->y;
        int r= v1.z - this->z;
        Vector3 res = Vector3(p, q, r);

        return res;
    }

    Vector3 multiply_scalar(float t){
        float p = this->x * t;
        float q= this->y * t;
        float r= this->z  * t;
        Vector3 res = Vector3(p, q, r);

        return res;
    }

    Vector3 scaleDown_scalar(float t){
        float p = this->x / t;
        float q= this->y  / t;
        float r= this->z  / t;
        Vector3 res = Vector3(p, q, r);

        return res;
    }

    float dot(Vector3 v1){
        float p = v1.x * this->x;
        float q= v1.y  * this->y;
        float r= v1.z  * this->z;
        float res = p+q+r;

        return res;
    }

    Vector3 cross(Vector3 v){
        Vector3 res = Vector3(-v.y*this->z + this->y * v.z, -v.z*this->x + this->z * v.x, -v.x*this->y + this->x * v.y);
        return res;

    }

    void reverse(){
        x=-x;
        y=-y;
        z=-z;
    }

    float modulus(){
        return sqrt((this->dot(*this)));
    }

    Vector3 unit(){
        Vector3 res = this->scaleDown_scalar(this->modulus());
        return res;

    }

    float STP(Vector3 v1, Vector3 v2){
        return this->dot(v1.cross(v2));
    }

    Vector3 VTP(Vector3 v1, Vector3 v2){
        return this->cross(v1.cross(v2));
    }

    void print(){
        std::cout << this->x << "  " << this->y << "  " << this->z << std::endl;
    }


};


float vol_ppd(Vector3 v1, Vector3 v2, Vector3 v3){
    return abs(v1.STP(v2, v3));
}

float area_triangle(Vector3 v1, Vector3 v2){
    return abs(0.5 * (v1.cross(v2)).modulus());
}


Vector3 vec_along(Vector3 v1, Vector3 v2){
    //component of v1 along v2
    Vector3 v_along = (v2.unit())<((v1*v2)/v2.modulus());
    return v_along;
}

Vector3 vec_perp(Vector3 v1, Vector3 v2){
    //component of v1 perp to v2
    Vector3 v_along = (v2.unit())<((v1*v2)/v2.modulus());
    Vector3 v_perp = v1 - v_along;
    return v_perp;
}