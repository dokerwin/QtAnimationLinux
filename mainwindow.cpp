#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttonSize =  50;
    scale      =  100;
    xShift     =  100;
    yShift     =  100;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAdd_clicked()
{

    QPushButton * btn = new QPushButton(this);
    btn->setText(QString::number(buttonList.size()));
    btn->setGeometry(ui->btnAdd->geometry());
    btn->show();
    buttonList.append(btn);

    rearrange();

}



void MainWindow::on_btnRemov_clicked()
{

    QPushButton* btn = buttonList.last();
    buttonList.removeLast();
    delete btn;

    rearrange();

}

void MainWindow::rearrange()
{
    int buttonCount= buttonList.size();
    float angleUnit= 6.28/buttonCount;
    for(int i=0;i<buttonCount;i++){
        QPushButton * btn= buttonList.at(i);
        QPropertyAnimation *animation
          = new QPropertyAnimation(btn, "geometry");
        animation->setDuration(1000);
        animation->setEasingCurve(QEasingCurve::Linear);
        animation->setEndValue(QRectF(cos(angleUnit * i)*
        scale +xShift, sin(angleUnit * i)* scale + yShift,buttonSize,buttonSize));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }



}
