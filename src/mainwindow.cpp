#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    BorderDetection::canrun=false;
    delete ui;
    delete detectBorders;
}

void MainWindow::updateui(QPixmap img)
{
    qDebug()<< "Hello" << QThread::currentThread();
    ui->label_2->setPixmap(img);
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileintro,filefilter,fileString,dirintro;
    fileintro ="Select an Image";
    filefilter ="Image (*.png; *.jpeg ; *.jpg)";
    dirintro=QDir::homePath();
    fileString =QFileDialog::getOpenFileName(this,fileintro,dirintro,filefilter);
    if(fileString == ""){
        qDebug() << "No file selected";
        return;
    }
    qDebug()<<fileString;
    filepath = fileString;
    QPixmap imgpix(filepath);
    ui->label->setPixmap(imgpix);
    qDebug()<<ui->label->size();
}


void MainWindow::on_pushButton_clicked()
{
    if(filepath==""){
        on_actionOpen_triggered();
    }

    if(detectBorders == nullptr){
        detectBorders = new BorderDetection();
    }

    QPixmap img = ui->label->pixmap();
    BorderDetection::canrun=true;
    QObject::connect(detectBorders,&BorderDetection::imageprocessed,
                     this,&MainWindow::updateui);
    detectBorders->detectborder(img);
    //ui->label_2->setPixmap(img);
}



