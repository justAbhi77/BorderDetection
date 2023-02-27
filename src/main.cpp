#include "headers/mainwindow.h"

#include <QApplication>
#include <QtConcurrent>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // set stylesheet
       QFile file(":/stylesheets/dark/stylesheet.qss");
       file.open(QFile::ReadOnly | QFile::Text);
       QTextStream stream(&file);
       a.setStyleSheet(stream.readAll());

    MainWindow w;
    w.show();

    return a.exec();
}
