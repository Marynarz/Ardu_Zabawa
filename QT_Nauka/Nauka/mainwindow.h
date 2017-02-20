#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextCodec>
#include <QLabel>
#include <QTranslator>
#include <QMenu>
#include <QAction>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QPushButton *button;
    QPushButton *butlab;
    QLabel *label;

    QMenu *menu;
    QAction *quitAction;
    void createMenus();
    void createStatusBar();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void foo();
};

#endif // MAINWINDOW_H
