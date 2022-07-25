#include "canvas2d.h"
#include "filterutils.h"


void Canvas2D::FilterIdentity(std::vector<RGBA> *canvas) {
    //TODO:
    std::vector<float> kernel={0,0,0,0,1,0,0,0,0};
    FilterUtils::Convolve2D(canvas->data(), m_canvasW, m_canvasH, kernel);
}
