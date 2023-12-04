#include "color.h"
#include "Vector3.h"

#include <iostream>
using namespace std;

int main()
 {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    /* Without color.h */
    /*

        for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    */

    /* With color.h */
    for (int j = 0; j < image_height; ++j) {
        clog << "\rScanlines remaining: " << (image_height - j) << ' ' << flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_color = color(0, 0, 0);
            if((i+j)%2==0){
                pixel_color = color(1,1,1);
            }
            else
            {
                pixel_color = color(0,0,0);
            }

            write_color(cout, pixel_color);
        }
    }

    clog << "\rDone.\n";
}