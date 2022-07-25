#include "supportcanvas2d.h"
#include <QPainter>
#include <QMessageBox>
#include <QFileDialog>
#include <QMouseEvent>
#include "iostream"

SupportCanvas2D::SupportCanvas2D()
{
    for(int i=0; i<250000; i++){
//        m_image.push_back(100);
//        m_image.push_back(0);
//        m_image.push_back(0);
//        m_image.push_back(0);
        m_image.push_back(RGBA(123,123,0,0));
    }
    m_canvas2d = new Canvas2D();
    m_canvas2d->m_canvas = &m_image;
}

SupportCanvas2D::~SupportCanvas2D() {
}


bool SupportCanvas2D::saveImageFile(const QString &file) {
}

void SupportCanvas2D::newImage() {
    // Load a black 500x500 image.
}

void SupportCanvas2D::mousePressEvent(QMouseEvent *event) {
    //TODO:
}

void SupportCanvas2D::mouseMoveEvent(QMouseEvent *event) {
    //TODO:
}

void SupportCanvas2D::mouseReleaseEvent(QMouseEvent *event) {
    // Move the mouse again in case this event is at a different position then the last event.
    //TODO:

}

void SupportCanvas2D::settingsChanged() {
}

bool SupportCanvas2D::loadImage(const QString &file){
    QImage myImage;
    myImage.load("C:\\Users\\ThinkPad\\Desktop\\CSCI1230 TA\\lab02\\Pencil\\test.jpg");
    myImage = myImage.convertToFormat(QImage::Format_RGBX8888);
    QByteArray arr = QByteArray::fromRawData((const char*)myImage.bits(), myImage.sizeInBytes());
    m_image.clear();
    for (int i =0 ; i<arr.size()/4; i++){
        m_image.push_back(RGBA(arr[4*i],arr[4*i+1],arr[4*i+2],arr[4*i+3]));
    }
    m_canvasW = myImage.width();
    m_canvasH = myImage.height();
    m_canvas2d->m_canvas = &m_image;
}

void SupportCanvas2D::filterImage(){
    m_canvas2d->filterImage();
}


