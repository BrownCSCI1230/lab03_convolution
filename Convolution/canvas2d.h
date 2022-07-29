#ifndef CANVAS2D_H
#define CANVAS2D_H

#include <QMainWindow>
#include <RGBA.h>
#include <settings.h>
class Canvas2D
{
public:
    Canvas2D();

    void settingsChanged();

    void mouseDown(int x, int y);
    void mouseDragged(int x, int y);
    void mouseUp(int x, int y);

    void paint(int x, int y, std::vector<float> mask, bool smudge);

    void filterImage();

    // Return an array containing the rows of the image one after another, starting from the top.
    // Each row is width() wide and there are height() rows, so this array will have
    // width() * height() elements.
    std::vector<uint8_t> *DisplayCanvas();
    //std::vector<RGBA> *DisplayColor();


    // used by support code to provide access to canvas data
    void setImage();
    void FilterGray();
    void FilterInvert();
    void FilterIdentity();
    void FilterShift();

    std::vector<RGBA> *m_canvas;
    int m_canvasW;
    int m_canvasH;
};

#endif // CANVAS2D_H
