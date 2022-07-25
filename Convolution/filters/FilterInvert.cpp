#include "canvas2d.h"
#include "filterutils.h"


void Canvas2D::FilterIdentity(std::vector<RGBA> *canvas) {
    //TODO:
    int width = m_canvasW;

    RGBA* current_pixel = nullptr;
    RGBA* current_row = canvas->data();

    // TODO: Task 8 [Optional] Use bitwise complement to set inversion

    for (int r = 0; r < m_canvasH; r++) {
        current_pixel = current_row;

        for (int c = 0; c < m_canvasW; c++) {
            // TODO: Task 7 Update the color with its inversion
            current_pixel->r = 255-current_pixel->r;
            current_pixel->g = 255-current_pixel->g;
            current_pixel->b = 255-current_pixel->b;


            // CONTINUED: Task 8 [Optional]

            current_pixel++;
        }
        current_row += width;
    }}
