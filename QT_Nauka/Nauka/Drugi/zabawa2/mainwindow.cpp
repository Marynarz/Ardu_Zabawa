#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     if(ui->pushButton->text() == QString("Hello World!"))
         ui->pushButton->setText(tr("Dupa!"));
     else
         ui->pushButton->setText(tr("Hello World!"));
}
