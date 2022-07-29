#include "canvas2d.h"
#include "filterutils.h"


unsigned char RGBAToGray(const RGBA &pixel) {
    // TODO: Task 5
    //eg:
    unsigned char Y = 0.299*pixel.r + 0.587*pixel.g + 0.114*pixel.b;

    return Y;

}

void Canvas2D::FilterGray() {
    int width = m_canvasW;

    RGBA* current_pixel = nullptr;

    /* Initialize the first pixel of the first row */
    std::vector<RGBA>* current_row = m_canvas;

    std::vector<RGBA>* data = m_canvas;
    size_t currentIndex = 0;

//    for (int r = 0; r < m_canvasH; r++) {
//        current_pixel = current_row;
//        currentIndex = r * width;

//        for (int c = 0; c < m_canvasW; c++) {
//            // TODO: Task 4
//            unsigned char grayScale = RGBAToGray(*current_pixel);

//            // TODO: Task 6
//            current_pixel->r = grayScale;
//            current_pixel->g = grayScale;
//            current_pixel->b = grayScale;


//            /* Advance to the next pixel */
//            current_pixel++;
//            currentIndex++;
//        }
//        current_row += width;
//    }
}
