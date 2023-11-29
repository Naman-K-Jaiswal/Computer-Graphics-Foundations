#include <iostream>
#include <cmath>

const double PI = 3.14159;

class shape{
  public:
   virtual float calculateArea(){};
   virtual float calculatePerimeter(){};




};
class Circle : public shape{
public:
   int radius;

  
  Circle(int rad){
    radius = rad;
  }
  float calculateArea() override{
    return PI*radius*radius;
  }
  float calculatePerimeter() override{
    return 2*PI*radius;
  }



};
class Rectangle : public shape{
public:
   float length;
   float breadth;

  
  Rectangle(int len , int bre){
    length = len;
    breadth = bre;
  }
  float calculateArea() override{
    return length*breadth;
  }
  float calculatePerimeter() override{
    return 2*(length+breadth);
  };



};
class Triangle : public shape{
public:
   int sidea;
   int sideb;
   int sidec;

  
  Triangle(int a, int b , int c){
    sidea= a;
    sideb =  b;
    sidec =  c;
    
  }
  float calculateArea() override{
    float semi = (sidea+sideb+sidec)/2;
    return sqrt(semi*(semi-sidea)*(semi-sideb)*(semi-sidec));
  }
  float calculatePerimeter() override{
    return sidea+sideb+sidec;
  };



};


int main() {

   Circle circle(7.0);
   Rectangle rectangle(4.2, 8.0);
   Triangle triangle(4.0, 4.0, 3.2);

   std::cout << "Circle: " << std::endl;
   std::cout << "Area: " << circle.calculateArea() << std::endl;
   std::cout << "Perimeter: " << circle.calculatePerimeter() << std::endl;

   std::cout << "\nRectangle: " << std::endl;
   std::cout << "Area: " << rectangle.calculateArea() << std::endl;
   std::cout << "Perimeter: " << rectangle.calculatePerimeter() << std::endl;

   std::cout << "\nTriangle: " << std::endl;
   std::cout << "Area: " << triangle.calculateArea() << std::endl;
   std::cout << "Perimeter: " << triangle.calculatePerimeter() << std::endl;

  return 0;
}
