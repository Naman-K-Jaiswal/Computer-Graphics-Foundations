#include <iostream>
#include <cmath>

const double PI = 3.14159;

class Shape
{
 virtual float calculateArea(){}
 virtual float calculatePerimeter(){}

};

class Circle:public Shape
{
  public:
  float radius;
  float area;
  float perimeter;

  Circle(float r)
  {
    radius=r;
  };
  float calculateArea() override
  {
   area=PI*radius*radius;
   return area;
  }
  float calculatePerimeter() override
  {
   perimeter=2*PI*radius;
   return perimeter;
  }
};

class Rectangle:public Shape
{
  public:
  float length,breadth;
  float area;
  float perimeter;

  Rectangle(float l,float b)
  {
    length=l;
    breadth=b;
  }
   float calculateArea() override
  {
   area=length*breadth;
   return area;
  }
  float calculatePerimeter() override
  {
   perimeter=2*(length+breadth);
   return perimeter;
  }

};

class Triangle:public Shape
{
  public:
  float side1,side2,side3;
  float area;
  float perimeter;

  Triangle(float a,float b,float c)
  {
    side1=a;
    side2=b;
    side3=c;
  }
   float calculateArea() override
  {
  float s;
  s=(side1+side2+side3)/2;
   area=sqrt(s*(s-side1)*(s-side2)*(s-side3));
   return area;
  }
  float calculatePerimeter() override
  {
   perimeter=side1+side2+side3;
   return perimeter;
  }
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
