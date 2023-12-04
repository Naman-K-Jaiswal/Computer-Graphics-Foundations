#include <iostream>
#include <cmath>

const double PI = 3.14159;

int main() {

//   Circle circle(7.0);
//   Rectangle rectangle(4.2, 8.0);
//   Triangle triangle(4.0, 4.0, 3.2);

//   std::cout << "Circle: " << std::endl;
//   std::cout << "Area: " << circle.calculateArea() << std::endl;
//   std::cout << "Perimeter: " << circle.calculatePerimeter() << std::endl;

//   std::cout << "\nRectangle: " << std::endl;
//   std::cout << "Area: " << rectangle.calculateArea() << std::endl;
//   std::cout << "Perimeter: " << rectangle.calculatePerimeter() << std::endl;

//   std::cout << "\nTriangle: " << std::endl;
//   std::cout << "Area: " << triangle.calculateArea() << std::endl;
//   std::cout << "Perimeter: " << triangle.calculatePerimeter() << std::endl;
 float percircle = 2*3.14*7.0;
 float areacircle = 3.14*7.0*7.0;
 std::cout<<"Circle:"<<std::endl;
 std::cout<<"Perimeter is" <<percircle<<std::endl;
 std::cout<<"Area is "<<areacircle<<std::endl;
 float perrectangle = (4.2+8.0)*2;
 float arearectangle = 4.2*8.0;
 std::cout<<"Rectangle :"<<std::endl;
 std::cout<<"Perimeter is :"<<perrectangle<<std::endl;
 std::cout<<"Area is :"<<arearectangle<<std::endl;
 float pertraingle = 4.0+4.0+3.2;
 float areatraingle = 0.5*2.0*3.7;
 std::cout<<"Traingle :"<<std::endl;
 std::cout<<"Perimeter is "<<pertraingle<<std::endl;
 std::cout<<"Area is "<<areatraingle<<std::endl;
  return 0;
}
