#include "matrix.h"
#include "frame.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>

Matrix::Matrix(){

}

void Matrix::clear()
{
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            delete lineEdit[i][j];
        }
    }
}

Matrix::Matrix(int x, int y)
{
    this->x = x;
    this->y = y;
    clear();
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            lineEdit[i][j] = new QLineEdit();
            lineEdit[i][j]->setFixedWidth(30);
            lineEdit[i][j]->setText("0");
        }
    }
}

void Matrix::setSize(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Matrix::fill(QVector<int> input, int x, int y)
{
    if(x * y != input.size()){
        return;
    }

    this->x = x;
    this->y = y;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            lineEdit[i][j]->setText(QString::number(input[j + i * y]));
        }
    }
}

void Matrix::vivod(QGridLayout &b1){
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
              b1.addWidget(lineEdit[i][j], i, j);
//              m1.lineEdit[i][j]->setText("0");
        }
    }
}

Matrix &Matrix::operator+=(const Matrix &z)
{
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            lineEdit[i][j]->setText(QString::number(lineEdit[i][j]->text().toInt() + z.lineEdit[i][j]->text().toInt()));
        }
    }
    return *this;
}

Matrix & Matrix::operator=(const Matrix &z)
{
    for(int i = 0; i < z.x; i++){
        for(int j = 0; j < z.y; j++){
            this->lineEdit[i][j]->setText(z.lineEdit[i][j]->text());
        }
    }
    return *this;
}

Matrix& Matrix::operator+(const Matrix &z)
{
    Matrix *matrix = new Matrix(x, y);
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            matrix->lineEdit[i][j]->setText(QString::number(lineEdit[i][j]->text().toInt() + z.lineEdit[i][j]->text().toInt()));
        }
    }
    return  *matrix;
}

Matrix & Matrix::operator-(const Matrix &z)
{
    Matrix *matrix = new Matrix(x, y);
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            matrix->lineEdit[i][j]->setText(QString::number(lineEdit[i][j]->text().toInt() - z.lineEdit[i][j]->text().toInt()));
        }
    }
    return *matrix;
}

Matrix & Matrix::operator*(const int &z)
{
    Matrix *matrix = new Matrix(x, y);
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            matrix->lineEdit[i][j]->setText(QString::number(lineEdit[i][j]->text().toInt() * z));
        }
    }
    return *matrix;
}


Matrix & Matrix::operator *(const Matrix &z)
{
    Matrix *matrix = new Matrix(x, z.y);

    for (int i = 0; i < x; i++)
    {
       for (int j = 0; j < z.y; j++)
       {
           int sum = 0;

           for (int n = 0; n < y; n++)
           {
                 sum += lineEdit[i][n]->text().toInt() * z.lineEdit[n][j]->text().toInt();
           }

           matrix->lineEdit[i][j]->setText(QString::number(sum));
       }
    }

    return *matrix;
}

bool Matrix::operator==(const Matrix &z)
{
    bool f = true;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(lineEdit[i][j]->text() != z.lineEdit[i][j]->text()){
                f = false;
                return false;
            }
        }
    }
    return f;
}

std::ostream &operator <<(std::ostream &os, Matrix & matrix)
{
    os << matrix.x << " "<< matrix.y << std::endl;
    for(int i = 0; i < matrix.x; i++)
    {
        for(int j = 0; j < matrix.y; j++)
        {
            os << matrix.lineEdit[i][j]->text().toInt() << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream & operator>>(std::istream &is, Matrix & matrix)
{
    int x;
    int y;
    is >> x;
    is >> y;
    if(matrix.x == x && matrix.y == y)
    {
        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                int z;
                is >> z;
                matrix.lineEdit[i][j]->setText(QString::number(z));
            }
        }
    }
    else QMessageBox::information(0, "Error", "Неправильный размер матрицы!" );

  return is;
}
