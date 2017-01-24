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

    butlab = new QPushButton(tr("&Etykieta"),this);
    butlab->setGeometry(175,90,150,75);

    label = new QLabel(tr("Etykietka"),this);
    label->setGeometry(225,150,150,75);

    connect(button,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(butlab,SIGNAL(clicked()),this, SLOT(foo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::foo()
{
    label->setText(tr("Wesola etykieta ;)"));
}
