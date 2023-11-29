#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159;
class Shape{
  public:
  virtual double calculateArea(){};
  virtual double calculatePerimeter(){};
};
class Circle: public Shape
{
  public:
  double r;
  Circle(double x){
    r=x;
  }
  double calculateArea() override{
    return PI*r*r;
  }
  double calculatePerimeter() override{
    return 2*PI*r;
  }
};
class Rectangle: public Shape
{
  public:
  double l;
  double b;
  Rectangle(double x,double y){
    l=x;
    b=y;
  }
  double calculateArea() override{
    return l*b;
  }
  double calculatePerimeter() override{
    return 2*(l+b);
  }
};
  class Triangle: public Shape
{
  public:
  double a;
  double b;
  double c;
  Triangle(double x,double y, double z){
    a=x;
    b=y;
    c=z;
  }
  double calculateArea() override{
    double s=(a+b+c)/2;
    double area=sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
  }
  double calculatePerimeter() override{
    return a+b+c;
  }
};
int main() {

   Circle circle(7.0);
   Rectangle rectangle(4.2, 8.0);
   Triangle triangle(4.0, 4.0, 3.2);

   cout << "Circle: " << endl;
   cout << "Area: " << circle.calculateArea() << endl;
   cout << "Perimeter: " << circle.calculatePerimeter() << endl;

   cout << "\nRectangle: " << endl;
   cout << "Area: " << rectangle.calculateArea() << endl;
   cout << "Perimeter: " << rectangle.calculatePerimeter() << endl;

   cout << "\nTriangle: " << endl;
   cout << "Area: " << triangle.calculateArea() << endl;
   cout << "Perimeter: " << triangle.calculatePerimeter() << endl;

  return 0;
}