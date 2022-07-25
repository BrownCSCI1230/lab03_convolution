#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include <QMainWindow>
#include "supportcanvas2d.h"
#include "canvas2d.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_supportcanvas = new SupportCanvas2D();

    QImage myImage;
    myImage.load("C:\\Users\\ThinkPad\\Desktop\\CSCI1230 TA\\lab02\\Pencil\\test.jpg");
    myImage = myImage.convertToFormat(QImage::Format_RGBX8888);

//    QImage other;
//    other.load("C:\\Users\\ThinkPad\\Desktop\\CSCI1230 TA\\lab02\\Pencil\\canvas.jpg");

    std::cout<<myImage.width()<<myImage.height()<<std::endl;
    QByteArray arr = QByteArray::fromRawData((const char*)myImage.bits(), myImage.sizeInBytes());





//    std::cout<<arr.size()<<std::endl;
//    std::cout<<int(uint8_t (arr.data()[1673]))<<" "<<int(uint8_t (arr.data()[167]))<<std::endl;
//    ui->label->setPixmap(QPixmap::fromImage(other));

    //option 1:directly edit raw data, by passing a std::vector
    //exp:
    std::vector<RGBA> buf;

    m_canvas = &buf;

    //load files
    QString filename = "C:\\Users\\ThinkPad\\Desktop\\CSCI1230 TA\\lab02\\Pencil\\test.jpg";
    m_supportcanvas->loadImage(filename);




    //show canvas
    m_canvas= m_supportcanvas->getImage();
    QByteArray* img = new QByteArray(reinterpret_cast<const char*>(m_canvas->data()), 4*m_canvas->size());
    QImage now = QImage((const uchar*)img->data(),m_supportcanvas->getWidth(), m_supportcanvas->getHeight(), QImage::Format_RGBX8888);
    ui->label->setPixmap(QPixmap::fromImage(now));
    ui->label->show();
    std::cout<<"got to Qimage show"<<std::endl;


}

MainWindow::~MainWindow()
{
    delete ui;
}

