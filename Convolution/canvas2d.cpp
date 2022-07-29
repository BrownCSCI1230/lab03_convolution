#include "canvas2d.h"
#include <vector>

Canvas2D::Canvas2D()
{
}

void Canvas2D::settingsChanged() {

}

std::vector<uint8_t> *Canvas2D::DisplayCanvas(){
    //Task 4:Return the pointer to the vector you just created
//        return &m_canvasData;
}

//std::vector<RGBA> *Canvas2D::DisplayColor(){
//    //Task 8:Return the pointer to the colorcanvasdata you just created
//    //eg:
//    return &m_colorCanvasData
//}


void Canvas2D::mouseDown(int x, int y) {
    // Brush TODO: handle mouse events
}

void Canvas2D::mouseDragged(int x, int y) {
    // Brush TODO: handle mouse events
}

void Canvas2D::mouseUp(int x, int y) {
    // Brush TODO: handle mouse events
}

void Canvas2D::paint(int x, int y, std::vector<float> mask, bool smudge) {
    // Brush TODO: paint canvas using mask
}

void Canvas2D::filterImage() {
    // Filter TODO: filter the image on canvas using the selected filter
    if(settings.filterType == 0){FilterInvert();}
    if(settings.filterType == 1){FilterGray();}
    if(settings.filterType == 2){FilterIdentity();}
    if(settings.filterType == 3){FilterShift();}
    if(settings.filterType == 4){FilterShift();}
}

void Canvas2D::setImage() {
}
