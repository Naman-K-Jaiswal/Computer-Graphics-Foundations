#include "color.h"
#include "vec3.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


float mandelbrot_calc(float i, float j, float max_iter, float res){
    float iter = 0.00;
    float x = 0.00;
    float y = 0.00;
    while(x*x + y*y <= res && iter < max_iter){
        float x_temp = x*x - y*y + i;
        y = 2*x*y + j;
        x = x_temp;
        iter = iter + 1;
    }

    return iter;


}

int main(){

    float image_width = 600.00;
    float image_height = 600.00;

    ofstream file_;
    file_.open("mandelbrot.ppm");

    if(file_.is_open()){
        file_ << "P3\n";
        file_ << image_width ;
        file_ << " ";
        file_ << image_height;
        file_ << "\n255\n";

        for(int i=0; i<image_width; ++ i){ // 0 to 255
            for(int j=0; j<image_height; ++j){
                float i_ = (2.47*i)/image_width - 2.00 ; // -2 to 0.47
                float j_ = (2.24*j)/image_height - 1.12; // -1.12 to 1.12

                float max_iter = 60.00;
                float res = 4.00;
                float k = mandelbrot_calc(i_, j_, max_iter, res); // k is from 0 to max_iter
                
                float t = k/max_iter;
                auto pc = color(0.17*(1-t), 0.65*(1-t), 0.94*(1-t));
                write_color(file_, pc);

        }
    }


    } 

    file_.close();
    
}