#ifndef BORDERDETECTION_H
#define BORDERDETECTION_H

#include <QObject>
#include <QtConcurrent>
#include <QFuture>
#include <QPixmap>

class BorderDetection : public QObject
{
    Q_OBJECT
public:
    explicit BorderDetection(QObject *parent = nullptr);
    static bool canrun;
    void detectborder(QPixmap);
    void test();
    void DetectAlgo(QPixmap);

private:
    QColor changepixel(QColor,QColor,QColor,QColor);

signals:
    void imageprocessed(QPixmap);
};

#endif // BORDERDETECTION_H
