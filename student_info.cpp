#include "student_info.h"
#include "ui_student_info.h"
#include "mainwindow.h"
#include "globle.h"
#include "student.h"

student_info::student_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::student_info)
{
    ui->setupUi(this);
}

student_info::~student_info()
{
    delete ui;
}

void student_info::setID(QString idname)
{
    ID=idname;
}

void student_info::on_pushButton_clicked()
{
    QString id=ID;
    QString name=ui->nameEdit->text();
    QString sex=ui->sexEdit->text();
    QString age=ui->ageEdit->text();
    QString major=ui->majorEdit->text();
    QString pw=ui->pwEdit->text();


    QSqlQuery query;
    query.exec("select Sno from S");
    bool T2=true;
    while(query.next())
    {
        QString id1= query.value(0).toString();
        if(id.compare(id1)==0)
        {
            QString sql;
            sql = QString("UPDATE  s  set name= '%2', sex='%3', age='%4', major='%5', password='%6'\
                           where Sno='%1'")
                            .arg(id).arg(name).arg(sex).arg(age).arg(major).arg(pw);

            QSqlQuery query;
            bool ok = query.exec(sql);
            if(ok)
            {
                QMessageBox::information(this ,tr("提示") , tr("更改成功!"));
                T2=false;
            }
            else
            {
                QMessageBox::information(this ,tr("提示") , tr("更改失败!"));
                T2=false;
            }

        }
    }
    if(T2==true)
        QMessageBox::information(this ,tr("提示") , tr("该编号不存在，无法更改"));
}
