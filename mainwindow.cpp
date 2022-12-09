#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    active = false;


    ui->tableWidget->hide();

    chooseFilesText = new QLabel("Вы не выбрали файлы. Для выбора файла(или папки) выберите Открыть",this);
    chooseFilesText->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpInterface()
{
    chooseFilesText->setVisible(false);
    ui->tableWidget->show();
    QVector<QString> btnText({"Имя","Размер","Разрешение","Глубина","Сжатие"});
    for(int i = 0;i < 5;i++){
        ui->tableWidget->setHorizontalHeaderItem(i,new QTableWidgetItem(btnText[i]));
    }
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    chooseFilesText->setGeometry(width()*0.18,height()*0.2,700,300);
}

void MainWindow::processImage(QString filename, int i){
    QElapsedTimer timer;
    timer.start();
    img.load(filename);
    qDebug() << timer.elapsed();
    timer.restart();
    QFileInfo fileinfo(filename);
    ui->tableWidget->setItem(i,0,new QTableWidgetItem(fileinfo.fileName()));
    QSize size = img.size();
    ui->tableWidget->setItem(i,1,new TableWidgetItemRes(QString::number(size.width()) + "x" + QString::number(size.height())));
    ui->tableWidget->setItem(i,2,new TableWidgetItemRes(QString::number(qRound(img.dotsPerMeterX()/39.37)) + "x" + QString::number(qRound(img.dotsPerMeterY()/39.37))));
    ui->tableWidget->setItem(i,3,new TableWidgetItemNumber(QString::number(img.bitPlaneCount())));
    ui->tableWidget->setItem(i,4,new QTableWidgetItem(fileinfo.suffix().toLower() == "bmp"? "Нет":"Есть"));
    qDebug() << timer.elapsed();
}


void MainWindow::on_a_open_triggered()
{
    QDir directory(QFileDialog::getExistingDirectory(this, tr("Open Folder")));
    if(directory.isEmpty())
        return;
    files = directory.entryList(QStringList() << "*.jpg" << "*.png" <<"*.bmp" << "*.tiff" << "*.tif" << "*.gif" << "*.pcx",QDir::Files);
    ui->tableWidget->clear();
    for(int i = 0; i < files.size();i++)
    {
        if(ui->tableWidget->rowCount()<(i+1))
            ui->tableWidget->insertRow(i);
        processImage(directory.path()+"/"+files[i],i);
    }
    setUpInterface();
}



void MainWindow::on_a_openFile_triggered()
{
   ui->tableWidget->clear();
   QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"/home",tr("Images (*.png *.xpm *.jpg *.bmp *.tiff *.gif *.pcx)"));
   if(filename.isNull())
       return;
   if(ui->tableWidget->rowCount()==0)
       ui->tableWidget->insertRow(0);
   processImage(filename,0);
   setUpInterface();
}
