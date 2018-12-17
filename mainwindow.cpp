#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include "frame.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Frame * frame = new Frame();
//    setCentralWidget(frame);
//    gridLayoutVerx = new QGridLayout(this);
//    gridLayoutVerx->addWidget(frame);
//    QBoxLayout *boxLayoutVerx = new QBoxLayout(QBoxLayout::Down, this);
//    boxLayoutVerx->addWidget(frame);
//    setLayout();

    setGeometry(300,300,700,400);
}

MainWindow::~MainWindow()
{
    delete ui;
}
