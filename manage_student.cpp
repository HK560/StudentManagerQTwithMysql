#include "manage_student.h"
#include "ui_manage_student.h"
#include "mainwindow.h"
#include "globle.h"
#include "manage.h"

manage_student::manage_student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manage_student)
{
    ui->setupUi(this);
    ui->seeAllButton->hide();
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    headers<<"ID"<<"姓名"<<"性别"<<"年龄"<<"专业"<<"密码";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(100);
    on_seeAllButton_clicked();
}

manage_student::~manage_student()
{
    delete ui;
}


void manage_student::on_insertButton_clicked()
{
    QString id=ui->idLineEdit->text();
    QString username=ui->nameLineEdit->text();
    QString sex=ui->sexLineEdit->text();
    QString age=ui->ageLineEdit->text();
    QString zhuanye=ui->majorLineEdit->text();
    QString password=ui->passwardLineEdit->text();

    QSqlQuery query;
    query.exec("select Sno from S");
    bool T2=true;
    while(query.next())
    {
        QString id1= query.value(0).toString();

        if(id.compare(id1)==0)
        {
            QMessageBox::information(this ,tr("提示") , tr("该编号已存在不允许再次添加!"));
            T2=false;
        }
    }
    if(T2==true)
    {
        QString sql;
        sql = QString("insert into S  VALUES ('%1', '%2', '%3','%4','%5','%6' )")
                .arg(id).arg(username).arg(sex).arg(age).arg(zhuanye).arg(password);


        bool ok = query.exec(sql);
        if(ok)
            QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
        else
            QMessageBox::information(this ,tr("提示") , tr("添加失败!"));

    }
    on_seeAllButton_clicked();

}

void manage_student::on_updateButton_clicked()
{
    QString id=ui->idLineEdit->text();
    QString username=ui->nameLineEdit->text();
    QString sex=ui->sexLineEdit->text();
    QString age=ui->ageLineEdit->text();
    QString zhuanye=ui->majorLineEdit->text();
    QString password=ui->passwardLineEdit->text();

    QSqlQuery query;
    query.exec("select Sno from S");
    bool T2=true;
    while(query.next())
    {
        QString id1= query.value(0).toString();
        if(id.compare(id1)==0)
        {
            QString sql;
            sql = QString("UPDATE  S  set name= '%2', sex='%3', age='%4', major='%5', password='%6'\
                           where Sno='%1'")
                           .arg(id).arg(username).arg(sex).arg(age).arg(zhuanye).arg(password);

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

    on_seeAllButton_clicked();
}

void manage_student::on_deleteButton_clicked()
{
    QString id=ui->idLineEdit->text();

    QSqlQuery query;
    query.exec("select Sno from S");
    bool T2=true;
    while(query.next())
    {
        QString id1= query.value(0).toString();

        if(id.compare(id1)==0)
        {
            QString sql;
            sql = QString("DELETE FROM S "
                          " where Sno = '%1' ").arg(id);

            QSqlQuery query;
            bool ok = query.exec(sql);
            if(ok)
            {

                QMessageBox::information(this ,tr("提示") , tr("删除成功!"));
                T2=false;
            }
            else
            {
                QMessageBox::information(this ,tr("提示") , tr("删除失败!"));
                T2=false;
            }

        }
    }
    if(T2==true)
        QMessageBox::information(this ,tr("提示") , tr("改编号不存在无法删除"));

    on_seeAllButton_clicked();
}

void manage_student::on_seeAllButton_clicked()
{

    QSqlQuery query;

    query.exec("select * from S");
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    int row=0;
    while(query.next())
    {
        for(int i  = 0 ; i <6; i++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(query.value(i).toString());
            ui->tableWidget->setItem(row, i, item);
        }
        row++;
    }

}

void manage_student::on_backButton_clicked(){
    ////manage *dh;
    this->hide();
   // dh=new manage ;
   // dh->show();
}
