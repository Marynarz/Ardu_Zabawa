#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    createMenus();
    createStatusBar();

    button = new QPushButton(tr("&Wciśnij mnie ;)"),this);
    button->setGeometry(50,45,150,75);

    butlab = new QPushButton(tr("&Etykieta"),this);
    butlab->setGeometry(175,90,150,75);

    label = new QLabel(tr("Etykietka"),this);
    label->setGeometry(225,150,150,75);

    connect(button,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(butlab,SIGNAL(clicked()),this, SLOT(foo()));

    setMinimumSize(200,200);
    resize(480,320);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::foo()
{
    label->setText(tr("Wesola etykieta ;)"));
}

void MainWindow::createMenus()
{
    menu = menuBar()->addMenu(tr("&Plik"));

    quitAction = new QAction(tr("&Wyjscie"),this);
    quitAction->setStatusTip(tr("Wyjdz z programu"));
    connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));
    menu->addAction(quitAction);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Gotowy"));
}

void MainWindow::on_button1_clicked()
{

}
