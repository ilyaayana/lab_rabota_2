#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include <iostream>
#include <tablewidgetitemnumber.h>
#include <tablewidgetitemres.h>
#include <QImage>
#include <QElapsedTimer>
#include <QHBoxLayout>
#include <QPushButton>
#include <QtMath>
#include <QDebug>

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
    void on_a_open_triggered();

    void on_a_openFile_triggered();

private:
    Ui::MainWindow *ui;
    QStringList files;
    QPixmap pix;
    QLabel* choseFilesText;
    bool active;
    QImage img;

    void processImage(QString , int);

    void setUpInterface();
    void paintEvent(QPaintEvent*);

};
#endif // MAINWINDOW_H
