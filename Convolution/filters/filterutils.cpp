#include "filterutils.h"
#include <algorithm>
#include "math.h"
#include <cstring>
#include <cstdlib>
#include <memory>
#include <iostream>
using namespace std;

namespace FilterUtils {

inline unsigned char REAL2byte(float f) {
    int i = static_cast<int>((f * 255.0 + 0.5));
    return (i < 0) ? 0 : (i > 255) ? 255 : i;
}

void Convolve2D(RGBA* data, int width, int height, const std::vector<float> &kernel) {
    // TODO: Task 9 Create buffer to store new image data

    RGBA * result = new RGBA[width * height];


    // TODO: Task 10 Obtain kernel dimension
    int dimension = sqrt(double(kernel.size()));


    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            size_t centerIndex = r * width + c;

            // TODO: Task 11 Initialize color to accumulate convolution data
            float red_acc = 0;
            float green_acc = 0;
            float blue_acc = 0;


            // TODO: Task 12
            // Iterate over the kernel using the value from task 10
            // Obtain the value at current index of kernel
            // Find correct index in original image data
            // Accumulate the kernel applied to pixel value in color_acc
            for(int x = -floor(dimension/2); x<= floor(dimension/2); x++){

                for(int y = -floor(dimension/2); y<=floor(dimension/2); y++){
                    if(r+x<0 || r+x>=height || c+y<0 || c+y >=width){continue;}
                    RGBA pixel = data[centerIndex+ 3*x + y];
                    float weight = kernel[3*(x+floor(dimension/2)) + y+floor(dimension/2)];
                    red_acc = red_acc + weight*float(pixel.r)/255;
                    green_acc = green_acc + weight*float(pixel.g)/255;
                    blue_acc = blue_acc + weight*float(pixel.b)/255;
                }
            }

            // TODO: Task 13 Ignore outside bounds


            // TODO: Task 14 Update buffer with accumulated color
//            RGBA newPix = RGBA(REAL2byte(red_acc), REAL2byte(green_acc), REAL2byte(blue_acc), 255);
            result[centerIndex] = RGBA(REAL2byte(red_acc), REAL2byte(green_acc), REAL2byte(blue_acc), 255);
        }
    }

    // TODO: Task 15 Copy over buffer to canvas data
    for (int i = 0; i< width*height; i++){
        data[i] = result[i];
    }
    memcpy(data, result, sizeof(RGBA)*width*height);

    delete [] result ;

}
}

