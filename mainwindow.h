#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "math.h"
#include<QPropertyAnimation>
#include<QPushButton>

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
    void on_btnAdd_clicked();

    void on_btnRemove_clicked();

    void on_btnRemov_clicked();


private:
    Ui::MainWindow *ui;
    int xShift, yShift, scale, buttonSize;

    QList <QPushButton*> buttonList;

    void rearrange();


};
#endif // MAINWINDOW_H
