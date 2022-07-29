#include "canvas2d.h"
#include "filterutils.h"


void Canvas2D::FilterIdentity() {
    //TODO:
    std::vector<float> kernel={0,0,0,0,1,0,0,0,0};
    FilterUtils::Convolve2D(m_canvas, m_canvasW, m_canvasH, kernel);
}
