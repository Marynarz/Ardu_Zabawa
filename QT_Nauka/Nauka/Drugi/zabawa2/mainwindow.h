#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool Labelka;
    QTime czas;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void aktualizacjaCzasu(QTime czas);

private slots:
    //void on_pushButton_clicked();
    void startTimer();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
