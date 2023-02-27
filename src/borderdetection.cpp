#include "headers/borderdetection.h"

bool BorderDetection::canrun = false;

BorderDetection::BorderDetection(QObject *parent)
    : QObject{parent}
{

}

void BorderDetection::detectborder(QPixmap piximage)
{
    QFuture obj = QtConcurrent::run([=]() {
        DetectAlgo(piximage);
    });
}

void BorderDetection::DetectAlgo(QPixmap piximage)
{
    qDebug() << "Hello From Algo" << QThread::currentThread();
    QImage image = piximage.toImage();
    QColor obj1,obj2,obj3,obj4,Crgb;
    for (int i = 0; i < image.width()-1; ++i) {
        for (int j = 0; j < image.height()-1; ++j) {
            if(!canrun) return;
            obj1=image.pixelColor(i,j);
            obj2=image.pixelColor(i+1,j);
            obj3=image.pixelColor(i,j+1);
            obj4=image.pixelColor(i+1,j+1);
            Crgb = changepixel(obj1,obj2,obj3,obj4);
            image.setPixelColor(i,j,Crgb);
            qDebug() << "processing "<< i<<" "<<j << QThread::currentThread();
            QThread::currentThread()->msleep(2);
        }
    }
    qDebug()<< "Image processed";
    emit imageprocessed(QPixmap::fromImage(image));
}

QColor BorderDetection::changepixel(QColor obj1, QColor obj2, QColor obj3, QColor obj4)
{
    int r= (std::abs(obj1.red()-obj2.red()) + std::abs(obj3.red()-obj4.red()))/2;
    int g= (std::abs(obj1.blue()-obj2.blue()) + std::abs(obj3.blue()-obj4.blue()))/2;
    int b= (std::abs(obj1.green()-obj2.green()) + std::abs(obj3.green()-obj4.green()))/2;

    obj1.setRed(r);
    obj1.setGreen(g);
    obj1.setBlue(b);
    obj1.setAlpha(255);

    return obj1;
}
