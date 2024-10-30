#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "btn1.h"
#include <QDebug>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    btn1 *demobtn1 = new btn1(":/res/btnRemove.png", "清除", 50, 50, 12);
    demobtn1->setParent(this);

    connect(demobtn1, &QPushButton::pressed, [=]()
    {
        demobtn1->zoom1();

    });
    connect(demobtn1, &QPushButton::released, [=]()
    {
        demobtn1->zoom2();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

