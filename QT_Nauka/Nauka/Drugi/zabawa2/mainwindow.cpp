#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Labelka = true;
    czas = QTime::currentTime();
    ui->setupUi(this);
    aktualizacjaCzasu(czas);
    ui->pushButton->setText(tr("Poczatek!"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     if(Labelka||(ui->pushButton->text() == QString("Hello World!")))
        {ui->label->setText(tr("Dupa!"));
         Labelka = false;}
     else
        {aktualizacjaCzasu(QTime::currentTime());
         Labelka = true;}
}

void MainWindow::aktualizacjaCzasu(QTime czas)
{
    ui->label->setText(czas.toString());
}
