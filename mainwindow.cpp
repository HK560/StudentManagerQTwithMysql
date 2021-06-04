#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include "globle.h"
#include "manage.h"
#include <QDesktopServices>
#include <QUrl>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("学生选课系统");
    ui->Login_password->setEchoMode(QLineEdit::Password);
    connect(ui->Login_password,&QLineEdit::returnPressed,this,&MainWindow::on_LoginButton_clicked);
    ui->Login_username->setText("hk560");
    ui->Login_password->setText("01");
    this->move(700,400);
    ui->radioButton->setChecked(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LoginButton_clicked()
{
    QString username = ui->Login_username->text();
    QString password = ui->Login_password->text();
    qDebug()<<"用户名:"<<username<<"密码:"<<password;

    if (!openDatabase())
    {
        QMessageBox::warning(this, tr("错误"), tr("打开数据库失败!"));
        return ;
    }

    if( ui->radioButton->isChecked()){
        QSqlQuery query;
        query.exec("select id,password from Admin");
        bool T1=false;
        while(query.next())
        {
            QString user = query.value(0).toString();
            QString pass = query.value(1).toString();
            qDebug() << user << pass ;
            if(username.compare(user)==0&&password.compare(pass)==0){
                password_qj=password;
                username_qj=username;
                T1=true;
                this->hide();
                m=new manage;
                m->show();
            }
        }


        if(T1==false)
            QMessageBox::information(this, "警告", "用户名或密码错误");

    }

    if( ui->radioButton_2->isChecked()){


        QSqlQuery query;
        query.exec("select Sno,password from S");
        bool T=false;
        while(query.next())
        {
            QString user = query.value(0).toString();
            QString pass = query.value(1).toString();
            qDebug() << user << pass ;
            if(username.compare(user)==0&&password.compare(pass)==0){
                password_qj=password;
                username_qj=username;
                T=true;
                this->hide();
                f=new student;
                f->setID(user);
                f->show();

            }
        }

        if(T==false)
            QMessageBox::information(this, "警告", "用户名或密码错误");
    }



}

void MainWindow::on_remitButton_clicked()
{
    ui->Login_username->clear();
    ui->Login_password->clear();
}

void MainWindow::on_hk560Btn_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://blog.hk560.top/")));
}
