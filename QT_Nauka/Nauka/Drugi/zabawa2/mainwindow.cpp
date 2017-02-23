#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Labelka = false;
    czas = QTime::currentTime();
    ui->setupUi(this);
    aktualizacjaCzasu(czas);
    ui->pushButton->setText(tr("Poczatek!"));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(startTimer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pushButton_clicked()
{
     if(Labelka||(ui->pushButton->text() == QString("Hello World!")))
        {ui->label->setText(tr("Dupa!"));
         Labelka = false;}
     else
        {aktualizacjaCzasu(QTime::currentTime());
         Labelka = true;}
}*/

void MainWindow::startTimer()
{
    if(!Labelka)
    {
        czas.start();
        ui->label->setText("Poczatek:");
        ui->label_3->setText(czas.toString());
        ui->label_2->setText("Kiedy koniec?");
        Labelka = true;
    }
    else
    {
        ui->label_2->setText("Jeszcze nie!");
    }

}

void MainWindow::aktualizacjaCzasu(QTime czas)
{
    ui->label->setText(czas.toString());
}
