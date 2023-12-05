#include "color.h"
#include "vec3.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

float ball_present(int i, int j, int t, float image_width){
    //upto t= 100
    float acc = 0.675;
    float c_y = image_width/2;
    float c_x;
    float e=0.5;
    float v_1 = acc*40*e;
    if(t<=40){
        c_x = 40 + (0.5*acc)*t*t;
    }
    else if(t<=60){
        c_x = 580-v_1*(t-40)+0.5*acc*(t-40)*(t-40);
    }
    else if(t<=80){
        c_x = 445 + 0.5*acc*(t-60)*(t-60);
    }
    else if(t<=90){
        c_x = 580 - (v_1*e)*(t-80) + 0.5*acc*(t-80)*(t-80);
    }
    else if(t<=100){
        c_x = 546.25 + 0.5*acc*(t-90)*(t-90);
    }
    else{
        c_x = 580;
    }



    return (c_x-i)*(c_x-i) + (c_y-j)*(c_y-j);
    
}

int main(){

    float image_width = 600.00;
    float image_height = 600.00;
    int total_time = 100;
    for(int t =0; t < total_time; ++t){

        std::string text = "img-";
        if(t+1<=9){
            text += "00";
        }
        else if(t+1<=99){
            text += "0";
        }
        else{
            text = text;
        }

        text += std::to_string(t+1);
        text += ".ppm";
        ofstream file_;
        file_.open(text);
        if(file_.is_open()){
            file_ << "P3\n";
            file_ << image_width ;
            file_ << " ";
            file_ << image_height;
            file_ << "\n255\n";


            // for(int i =0 ; i<image_width; ++i){
            //     for(int j=0; j<image_height; ++j){
            //         float radius = 20;
            //         float d = ball_present(i, j, t, image_width);
            //         if(d <= radius*radius){
            //             write_color(file_, color(202, 237, 247));
            //         }
            //         else if(sqrtf(d) - radius <= 2.5){
            //             write_color(file_, color(33, 156, 197));
            //         }
            //         else if(sqrtf(d) - radius <= 18){
            //             float l = 45*exp2f(-0.25*(sqrtf(d)-radius) + 0.625);
            //             write_color(file_, color((33*l)/45,(156*l)/45, (197*l)/45 ));
            //         }
            //         else{
            //             write_color(file_, color(0, 0, 0));
            //         }
            //     }
            // }

            for(int i=0; i<image_width; ++i){
            for(int j=0; j<image_height; ++j){
                float radius = 20;
                float d = sqrt(ball_present(i, j, t, image_width)) - radius;
                if( fabs(d) <= 3){
                    write_color(file_, color(1, 1, 1));
                }
                else if(fabs(d)<=5.2){
                    write_color(file_, color(0.129, 0.611, 0.772));
                }
                else if(fabs(d)<=15){
                    float l = 45*exp2f(-0.4*fabs(d) + 2);
                    write_color(file_, color((0.129*l)/45,(0.611*l)/45, (0.772*l)/45 ));
                }
                else{
                    write_color(file_, color(0, 0, 0));
                }
            }
        }

        }

        file_.close();

    }

}
