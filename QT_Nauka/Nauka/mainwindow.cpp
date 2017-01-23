#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    button = new QPushButton(tr("&Wciśnij mnie ;)"),this);
    button->setGeometry(25,15,150,75);

    connect(button,SIGNAL(clicked()),qApp,SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
