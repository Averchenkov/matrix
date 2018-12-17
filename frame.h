#ifndef FRAME_H
#define FRAME_H
#include <QMainWindow>
#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QString>
#include <QListWidget>
#include <QLineEdit>
#include <QComboBox>
#include "matrix.h"
#include <QLayout>

#include <QFrame>

#include <QDialog>

namespace Ui {
class Frame;
}

class Frame : public QDialog
{
    Q_OBJECT

public:
    explicit Frame(QWidget *parent = nullptr);
    ~Frame();

    Ui::Frame *ui;

private:
    QBoxLayout *gridLayoutVerx;
    QGridLayout *gridLayoutMenu;
    QGridLayout *gridLayoutSize;
    QGridLayout *gridLayoutProblem;
    QGridLayout *gridLayoutListWidget;
    QGridLayout *gridLayoutButton1;
    QGridLayout *gridLayoutButton2;
    QGridLayout *gridLayoutButton3;
    QListWidget *listWidget;
    QPushButton *buttonListWidget;
    QPushButton *buttonComboBox;
    QPushButton *buttonDifference;
    QPushButton *buttonProblem;
    QPushButton *buttonOpen1;
    QPushButton *buttonOpen2;
    QPushButton *buttonSave;
    QComboBox *conboboxM1x;
    QComboBox *conboboxM1y;
    QComboBox *conboboxM2x;
    QComboBox *conboboxM2y;
    Matrix *m1;
    Matrix *m2;
    Matrix *m3;
//    void SetupProblem();

private slots:
    void on_buttonListWidget_clicked();
    void Problem(int, int, int, int, int, int, int);
    void Size(int);
    void Clear(QLayout &);
    void Sum();
    void Difference();
    void MultiOnNumber();
    void MultiOnVector();
    void Multiplication();
    void Equals();
    void Save();
    void Open1();
    void Open2();
    void on_buttonSum_clicked();
    void on_buttonDifference_clicked();
    void on_buttonMultiOnNumber_clicked();
    void on_buttonMultiOnVector_clicked();
    void on_buttonMultiplication_clicked();
    void on_buttonEquals_clicked();
};

#endif // FRAME_H
