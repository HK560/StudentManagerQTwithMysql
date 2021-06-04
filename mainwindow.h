#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include "student.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include<manage.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_LoginButton_clicked();
    void on_remitButton_clicked();

    void on_hk560Btn_clicked();

signals:
    void sendData(QString);

private:
    Ui::MainWindow *ui;
    student *f;
    manage *m;
};
#endif // MAINWINDOW_H
