#include "student_course.h"
#include "ui_student_course.h"
#include "mainwindow.h"
#include "globle.h"
#include "student.h"


student_course::student_course(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::student_course)
{
    ui->setupUi(this);
    header<<"课程编号"<<"课程名"<<"教师"<<"学分";

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //headers<<"ID"<<"姓名"<<"性别"<<"年龄"<<"专业"<<"密码";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setRowCount(100);

    QSqlQuery query;

    query.exec("select * from c");
    //ui->tableWidget->clear();
    //ui->tableWidget->setHorizontalHeaderLabels(header);

    int row=0;
    while(query.next())
    {
        for(int i  = 0 ; i <4; i++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(query.value(i).toString());
            ui->tableWidget->setItem(row, i, item);
        }
        row++;
    }

}

student_course::~student_course()
{
    delete ui;
}

void student_course::on_selectBtn_clicked()
{
//    SELECT cno from(select sno ,cno from sc where sno='st0001')as a where cno='C0001'
    QString cno=ui->lineEdit->text();
    QSqlQuery query;
    QString sql_1=QString("SELECT cno from(select sno ,cno from sc where sno='%1')as a where cno='%2'").arg(ID).arg(cno);
    QString sql_2=QString("SELECT cno from c where cno='%1'").arg(cno);
    query.exec(sql_2);
    query.first();
    if(query.value(0).isNull()==0){
        query.exec(sql_1);
        bool T2=true;
        query.first();
        if(query.value(0).isNull()==1)
        {

                QString sql;
                sql = QString("insert into sc VALUES ('%1','%2',NULL)")
                                .arg(ID).arg(cno);

                QSqlQuery query;
                bool ok = query.exec(sql);
                if(ok)
                {
                    QMessageBox::information(this ,tr("提示") , tr("选课成功!"));
                    T2=false;
                }
                else
                {
                    QMessageBox::information(this ,tr("提示") , tr("选课失败!"));
                    T2=false;
                }
        }
        else{
                if(T2==true)
                QMessageBox::information(this ,tr("提示") , tr("该课程已经选修"));
        }
    }else
        QMessageBox::information(this ,tr("提示") , tr("该课程不存在"));




    }

void student_course::on_outBtn_clicked()
{
    //DELETE FROM sc where sno='st0001' and cno='C0003'
    QString cno=ui->lineEdit->text();
    QSqlQuery query;
    QString sql_1=QString("SELECT cno from(select sno ,cno from sc where sno='%1')as a where cno='%2'").arg(ID).arg(cno);
    QString sql_2=QString("SELECT cno from c where cno='%1'").arg(cno);
    query.exec(sql_2);
    query.first();
    if(query.value(0).isNull()==0){
        query.exec(sql_1);
        bool T2=true;
        query.first();
        if(query.value(0).isNull()==0)
        {

                QString sql;
                sql = QString("DELETE FROM sc where sno='%1' and cno='%2'")
                                .arg(ID).arg(cno);

                QSqlQuery query;
                bool ok = query.exec(sql);
                if(ok)
                {
                    QMessageBox::information(this ,tr("提示") , tr("退选成功!"));
                    T2=false;
                }
                else
                {
                    QMessageBox::information(this ,tr("提示") , tr("退选失败!"));
                    T2=false;
                }
        }
        else{
                if(T2==true)
                QMessageBox::information(this ,tr("提示") , tr("没有选修该课程"));
        }
    }else
        QMessageBox::information(this ,tr("提示") , tr("该课程不存在"));
}

void student_course::setID(QString id)
{
    ID=id;
}
