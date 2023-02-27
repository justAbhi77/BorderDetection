#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QPixmap>
#include "borderdetection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_pushButton_clicked();
    void updateui(QPixmap);

private:
    Ui::MainWindow *ui;
    QString filepath;
    BorderDetection *detectBorders = nullptr;
};
#endif // MAINWINDOW_H
