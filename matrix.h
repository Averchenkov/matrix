#ifndef MATRIX_H
#define MATRIX_H
#include <QLineEdit>
#include <QGridLayout>

class Matrix
{
public:
    Matrix();
    Matrix(int, int);
    void Output(int, int);
    QLineEdit *lineEdit[1000][1000];
    void setSize(int, int);

    friend std::ostream &operator <<(std::ostream &, Matrix &);
    friend std::istream & operator>>(std::istream &, Matrix &);
    void fill(QVector<int> input, int x, int y);
    void clear();
    void vivod(QGridLayout &);
    Matrix & operator+=(const Matrix & z);
    Matrix & operator=(const Matrix & z);
    Matrix & operator+(const Matrix & z);
    Matrix & operator-(const Matrix & z);
    Matrix & operator*(const int & z);
    Matrix & operator*(const Matrix & z);
    bool operator==(const Matrix & z);
private:
    int x;
    int y;
};

#endif // MATRIX_H
