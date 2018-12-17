#include "frame.h"
#include "ui_frame.h"
#include <QMessageBox>
#include "matrix.h"
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QHBoxLayout>

Frame::Frame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);
    setVisible(true);

    gridLayoutVerx = new QBoxLayout(QHBoxLayout::LeftToRight, this);
    gridLayoutMenu = new QGridLayout();
    gridLayoutListWidget = new QGridLayout();

    buttonListWidget = new QPushButton("Выбрать");

    listWidget = new QListWidget();

    listWidget->addItem("Сумма двух матриц");
    listWidget->addItem("Разность двух матриц");
    listWidget->addItem("Умножение матрицы на число");
    listWidget->addItem("Умножение матрицы на вектор");
    listWidget->addItem("Умножение двух матриц");
    listWidget->addItem("Проверка равенства двух равенства");

    listWidget->setFixedWidth(270);

    gridLayoutVerx->addWidget(listWidget);
    gridLayoutVerx->addLayout(gridLayoutMenu);
    gridLayoutMenu->addLayout(gridLayoutListWidget, 0, 0);
    gridLayoutListWidget->addWidget(listWidget, 0, 0);
    gridLayoutListWidget->addWidget(buttonListWidget, 1, 0);

    gridLayoutProblem = new QGridLayout();
    gridLayoutSize = new QGridLayout();
    gridLayoutProblem->setHorizontalSpacing(10);
    gridLayoutVerx->addLayout(gridLayoutSize);
    gridLayoutVerx->addLayout(gridLayoutProblem);

    gridLayoutButton1 = new QGridLayout();
    gridLayoutButton2 = new QGridLayout();
    gridLayoutButton3 = new QGridLayout();

    connect(buttonListWidget, SIGNAL(clicked(bool)), this, SLOT(on_buttonListWidget_clicked()));
    setLayout(gridLayoutVerx);
    setGeometry(300,300,700,400);
}

void Frame::on_buttonListWidget_clicked()
{
    if (listWidget->currentItem()->text() == "Сумма двух матриц") {
        Size(1);
        connect(buttonComboBox, SIGNAL(clicked(bool)), this, SLOT(Sum()));
    }

    else if (listWidget->currentItem()->text() == "Разность двух матриц") {

        Size(1);
        connect(buttonComboBox, SIGNAL(clicked(bool)), this, SLOT(Difference()));
    }

    else if (listWidget->currentItem()->text() == "Умножение матрицы на число") {
        Size(1);
        connect(buttonComboBox, SIGNAL(clicked(bool)), this, SLOT(MultiOnNumber()));
    }


    else if (listWidget->currentItem()->text() == "Умножение матрицы на вектор") {
        Size(1);
        connect(buttonComboBox, SIGNAL(clicked(bool)), this, SLOT(MultiOnVector()));
    }


    else if (listWidget->currentItem()->text() == "Умножение двух матриц") {
        Size(2);
        connect(buttonComboBox, SIGNAL(clicked(bool)), this, SLOT(Multiplication()));
    }


    else if (listWidget->currentItem()->text() == "Проверка равенства двух равенства") {
        Size(1);
        connect(buttonComboBox, SIGNAL(clicked(bool)), this, SLOT(Equals()));
    }
}

void Frame::Sum()
{
    int x1 = conboboxM1x->currentText().toInt();
    int y1 = conboboxM1y->currentText().toInt();
    Problem(x1, y1, x1, y1, x1, y1, 3);
    connect(buttonProblem, SIGNAL(clicked(bool)), this, SLOT(on_buttonSum_clicked()));
}

void Frame::Difference()
{
    int x1 = conboboxM1x->currentText().toInt();
    int y1 = conboboxM1y->currentText().toInt();
    Problem(x1, y1, x1, y1, x1, y1, 3);
    connect(buttonProblem, SIGNAL(clicked(bool)), this, SLOT(on_buttonDifference_clicked()));
}



void Frame::MultiOnNumber()
{

    int x1 = conboboxM1x->currentText().toInt();
    int y1 = conboboxM1y->currentText().toInt();
    Problem(x1, y1, 1, 1, x1, y1, 3);
    delete buttonOpen2;
    connect(buttonProblem, SIGNAL(clicked(bool)), this, SLOT(on_buttonMultiOnNumber_clicked()));
}

void Frame::MultiOnVector()
{
    int x1 = conboboxM1x->currentText().toInt();
    int y1 = conboboxM1y->currentText().toInt();
    Problem(x1, y1, y1, 1, x1, 1, 3);
    connect(buttonProblem, SIGNAL(clicked(bool)), this, SLOT(on_buttonMultiOnVector_clicked()));
}

void Frame::Multiplication()
{

    int x1 = conboboxM1x->currentText().toInt();
    int y1 = conboboxM1y->currentText().toInt();
    int x2 = conboboxM2x->currentText().toInt();
    int y2 = conboboxM2y->currentText().toInt();

    if(y1 != x2){
        QMessageBox::information(this, "Error", "Число столбцов первой матрицы не равно числу строк второй матрицы!" );
    }
    else{
        Problem(x1, y1, x2, y2, x1, y2, 3);
        connect(buttonProblem, SIGNAL(clicked(bool)), this, SLOT(on_buttonMultiplication_clicked()));
    }
}

void Frame::Equals()
{
    int x1 = conboboxM1x->currentText().toInt();
    int y1 = conboboxM1y->currentText().toInt();
    Problem(x1, y1, x1, y1, 0, 0, 2);
    delete buttonSave;
    connect(buttonProblem, SIGNAL(clicked(bool)), this, SLOT(on_buttonEquals_clicked()));
}


void Frame::on_buttonSum_clicked()
{
    *m3 = *m2 + *m1;
}

void Frame::on_buttonDifference_clicked()
{
    *m3 = *m2 - *m1;
}

void Frame::on_buttonMultiOnNumber_clicked()
{
    *m3 = *m1 * m2->lineEdit[0][0]->text().toInt();
}

void Frame::on_buttonMultiOnVector_clicked()
{
    *m3 = *m2 * *m1;
}

void Frame::on_buttonMultiplication_clicked()
{
    *m3 = *m2 * *m1;
}

void Frame::on_buttonEquals_clicked()
{
    if(m1 == m2){
        QMessageBox::information(this, "Information", "Матрицы равны");
    }
    else{
        QMessageBox::information(this, "Information", "Матрицы не равны");
    }
}

void Frame::Problem(int x1, int y1, int x2, int y2, int x3, int y3, int z)
{
    Clear(*gridLayoutButton1);
    Clear(*gridLayoutButton2);
    Clear(*gridLayoutButton3);
    m1 = new Matrix(x1, y1);
    m2 = new Matrix(x2, y2);
    m3 = new Matrix(x3, y3);


    m1->vivod(*gridLayoutButton1);
    m2->vivod(*gridLayoutButton2);
    m3->vivod(*gridLayoutButton3);
    buttonProblem = new QPushButton("Решить");
    buttonOpen1 = new QPushButton("Открыть");
    buttonOpen2 = new QPushButton("Открыть");
    buttonSave = new QPushButton("Загрузить");

    gridLayoutProblem->addWidget(buttonOpen1, 1, 0);
    gridLayoutProblem->addWidget(buttonOpen2, 1, 1);
    gridLayoutProblem->addWidget(buttonSave, 1, 2);
    gridLayoutProblem->addWidget(buttonProblem, 2, 0, 2, z);
    connect(buttonOpen1, SIGNAL(clicked(bool)), this, SLOT(Open1()));
    connect(buttonOpen2, SIGNAL(clicked(bool)), this, SLOT(Open2()));
    connect(buttonSave, SIGNAL(clicked(bool)), this, SLOT(Save()));
}

void Frame::Size(int z)
{
    Clear(*gridLayoutSize);
    Clear(*gridLayoutButton1);
    Clear(*gridLayoutButton2);
    Clear(*gridLayoutButton3);
    Clear(*gridLayoutProblem);

    gridLayoutButton1 = new QGridLayout();
    gridLayoutButton2 = new QGridLayout();
    gridLayoutButton3 = new QGridLayout();
    gridLayoutProblem->addLayout(gridLayoutButton1, 0, 0);
    gridLayoutProblem->addLayout(gridLayoutButton2, 0, 1);
    gridLayoutProblem->addLayout(gridLayoutButton3, 0, 2);

    conboboxM1x = new QComboBox;
    conboboxM1y = new QComboBox;

    gridLayoutSize->addWidget(conboboxM1x, 0, 0);
    gridLayoutSize->addWidget(conboboxM1y, 0, 1);

    conboboxM1x->setFixedWidth(50);
    conboboxM1y->setFixedWidth(50);

    for(int i = 1; i <= 10; i++)
    {
        conboboxM1x->addItem(QString::number(i));
        conboboxM1y->addItem(QString::number(i));
    }
    buttonComboBox = new QPushButton("Выбрать");
    gridLayoutSize->addWidget(buttonComboBox, z, 0, z, 2);

    if(z == 2)
    {
        conboboxM2x = new QComboBox;
        conboboxM2y = new QComboBox;
        gridLayoutSize->addWidget(conboboxM2x, 1, 0);
        gridLayoutSize->addWidget(conboboxM2y, 1, 1);
        conboboxM2x->setFixedWidth(50);
        conboboxM2y->setFixedWidth(50);
        for(int i = 1; i <= 10; i++)
        {
            conboboxM2x->addItem(QString::number(i));
            conboboxM2y->addItem(QString::number(i));
        }
    }
}

void Frame::Clear(QLayout& layout)
{
    while (QLayoutItem* item = layout.takeAt(0)) {
        delete item->widget();
        delete item;
    }
}

void Frame::Open1()
{
    QString name_file = QFileDialog::getOpenFileName(this, tr("Open File"),"C:\\Users\\Aver\\Desktop",tr("txt(*.txt)"));


    std::ifstream fromfile;
    fromfile.open(name_file.toStdString());
    if(fromfile.is_open())
    {
        fromfile >> *m1;
    }
    fromfile.close();
}

void Frame::Open2()
{
    QString name_file = QFileDialog::getOpenFileName(this, tr("Open File"),"C:\\Users\\Aver\\Desktop",tr("txt(*.txt)"));

    std::ifstream fromfile;
    fromfile.open(name_file.toStdString());
    if(fromfile.is_open())
    {
        fromfile >> *m2;
    }
    fromfile.close();
}

void Frame::Save()
{

    QString name_file = QFileDialog::getOpenFileName(this, tr("Open File"),"C:\\Users\\Aver\\Desktop",tr("txt(*.txt)"));

    std::ofstream infile;
    infile.open(name_file.toStdString());
    if(infile.is_open())
    {
        infile << m3;
    }
    infile.close();
}

Frame::~Frame()
{
    delete ui;
}
