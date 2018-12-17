#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QGridLayout;
class QBoxLayout;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QGridLayout *gridLayoutVerx;
//    QBoxLayout *boxLayoutVerx;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
