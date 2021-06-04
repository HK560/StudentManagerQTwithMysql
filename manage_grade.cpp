#include "manage_grade.h"
#include "ui_manage_grade.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "manage.h"

manage_grade::manage_grade(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manage_grade)
{
    ui->setupUi(this);
    //ui->seeAllButton->hide();
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    headers<<"学号"<<"姓名"<<"课程号"<<"课程"<<"成绩";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(100);
    on_seeAllButton_clicked();
}

manage_grade::~manage_grade()
{
    delete ui;
}


void manage_grade::on_insertButton_clicked()
{
    QString sno=ui->snoLineEdit->text();
    QString cno=ui->cnoLineEdit->text();
    QString grade=ui->gradeLineEdit->text();

    QSqlQuery query;
    query.exec("select Sno,Cno from SC");
    bool T2=true;
    while(query.next())
    {
        QString s= query.value(0).toString();
        QString c= query.value(1).toString();
        if(s==sno&&c==cno)
        {
            QMessageBox::information(this ,tr("提示") , tr("该编号已存在不允许再次添加!"));
            T2=false;
        }
    }
    if(T2==true)
    {
        QString sql;
        sql = QString("insert into SC VALUES ('%1', '%2' , %3 )")
                .arg(sno).arg(cno).arg(grade);


        bool ok = query.exec(sql);
        if(ok)
            QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
        else
            QMessageBox::information(this ,tr("提示") , tr("添加失败!"));

    }
    on_seeAllButton_clicked();

}

void manage_grade::on_updateButton_clicked()
{
    QString sno=ui->snoLineEdit->text();
    QString cno=ui->cnoLineEdit->text();
    QString grade=ui->gradeLineEdit->text();

    QSqlQuery query;
    query.exec("select Sno,Cno from SC");
    bool T2=true;
    while(query.next())
    {
        QString s= query.value(0).toString();
        QString c= query.value(1).toString();
        if(s==sno&&c==cno)
        {
            QString sql;
            sql = QString("UPDATE SC set grade = %3 \
                           where Sno = '%1' and Cno='%2' ")
                    .arg(sno).arg(cno).arg(grade);


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

void manage_grade::on_deleteButton_clicked()
{
    QString sno=ui->snoLineEdit->text();
    QString cno=ui->cnoLineEdit->text();

    QSqlQuery query;
    query.exec("select Sno,Cno from SC");
    bool T2=true;
    while(query.next())
    {
        QString s= query.value(0).toString();
        QString c= query.value(1).toString();
        if(s==sno&&c==cno)
        {
            QString sql;
            sql = QString("DELETE FROM SC \
                           where Sno = '%1' and Cno='%2' ").arg(sno).arg(cno);

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

void manage_grade::on_seeAllButton_clicked()
{

    QSqlQuery query;
    query.exec("SELECT ns.sno, ns.name,es.cno,es.name as cname ,ns.grade FROM((SELECT a.*,b.name from sc as a LEFT JOIN s as b on a.Sno=b.Sno) as ns)LEFT JOIN c as es on ns.cno=es.Cno");
                   //query.exec("select * from SC");
                   ui->tableWidget->clear();
                   ui->tableWidget->setHorizontalHeaderLabels(headers);

                   int row=0;
                   QStringList rowdata;
                   while(query.next())
                   {
                       rowdata.clear();

                       QString sno = query.value(0).toString();
                       QString name = query.value(1).toString();
                       QString cno = query.value(2).toString();
                       QString cname = query.value(3).toString();
                       QString grade = query.value(4).toString();

               //        QString sql=QString("select name from s WHERE Sno='%1'").arg(id);
               //        query.exec(sql);
               //        QString name=query.value(0).toString();

                       rowdata<<sno<<name<<cno<<cname<<grade;
                       list_all_student.append(rowdata);

                       for(int i  = 0 ; i <rowdata .size() ; i++)
                       {
                           QTableWidgetItem *item = new QTableWidgetItem;
                           item->setText(rowdata.at(i));
                           ui->tableWidget->setItem(row , i , item);
                       }

                       row++;

                   }

               }

               void manage_grade::on_backButton_clicked(){
                   manage *dh;
                   this->hide();
                   dh=new manage ;
                   dh->show();
               }

               void manage_grade::on_avgGradeBtn_clicked()
               {
                   //SELECT avg from(SELECT sno, AVG(grade) as avg from sc GROUP BY sno)as a WHERE sno='st0001'


                   QString sno=ui->courseEdit_1->text();

                   QSqlQuery query;
                   QString sql=QString("SELECT avg from(SELECT cno, AVG(grade) as avg from sc GROUP BY cno)as a WHERE cno='%1'").arg(sno);
                   //query.exec(sql);
                   bool T2=true;
                   bool ok = query.exec(sql);
                   if(ok)
                   {
                       query.first();
                       if(query.value(0).isNull()==false){
                           QString AVGgrade=query.value(0).toString();
                           QString text=QString("课程编号为 %1 ，平均成绩为 %2 分").arg(sno).arg(AVGgrade);
                           QMessageBox::information(this ,tr("查询结果") , text);
                           T2=false;
                       }
                   }
                   else
                   {
                       QMessageBox::information(this ,tr("提示") , tr("查询失败!"));
                       T2=false;
                   }
                   if(T2==true)
                       QMessageBox::information(this ,tr("提示") , tr("该编号不存在，无法查询"));
               }

               void manage_grade::on_maxGradeBtn_clicked()
               {
                   //select max(grade) from sc where sno='st0002'
                   QString sno=ui->courseEdit_1->text();

                   QSqlQuery query;
                   QString sql=QString("select max(grade) from sc where cno='%1'").arg(sno);
                   //query.exec(sql);
                   bool T2=true;
                   bool ok = query.exec(sql);
                   if(ok)
                   {
                       query.first();
                       if(query.value(0).isNull()==false){
                           QString grade=query.value(0).toString();
                           QString text=QString("课程编号为 %1 ，最高成绩分数为 %2 分").arg(sno).arg(grade);
                           QMessageBox::information(this ,tr("查询结果") , text);
                           T2=false;
                       }
                   }
                   else
                   {
                       QMessageBox::information(this ,tr("提示") , tr("查询失败!"));
                       T2=false;
                   }
                   if(T2==true)
                       QMessageBox::information(this ,tr("提示") , tr("该编号不存在，无法查询"));
               }

               void manage_grade::on_minGradeBtn_clicked()
               {
                   //select min(grade) from sc where sno='st0002'
                   QString sno=ui->courseEdit_1->text();

                   QSqlQuery query;
                   QString sql=QString("select min(grade) from sc where cno='%1'").arg(sno);
                   //query.exec(sql);
                   bool T2=true;
                   bool ok = query.exec(sql);
                   if(ok)
                   {
                       query.first();
                       if(query.value(0).isNull()==false){
                           QString grade=query.value(0).toString();
                           QString text=QString("课程编号为 %1 ，最低成绩分数为 %2 分").arg(sno).arg(grade);
                           QMessageBox::information(this ,tr("查询结果") , text);
                           T2=false;
                       }
                   }
                   else
                   {
                       QMessageBox::information(this ,tr("提示") , tr("查询失败!"));
                       T2=false;
                   }
                   if(T2==true)
                       QMessageBox::information(this ,tr("提示") , tr("该编号不存在，无法查询"));
               }


               void manage_grade::on_sumCreditBtn_clicked()
               {
                    //SELECT sum( b.credit ) FROM( SELECT sno, cno FROM sc WHERE sno = 'st0001' ) AS a	LEFT JOIN c AS b ON a.cno  = b.Cno
                   QString sno=ui->courseEdit_2->text();

                   QSqlQuery query;
                   QString sql=QString("SELECT sum( b.credit ) FROM( SELECT sno, cno FROM sc WHERE sno = '%1' ) AS a LEFT JOIN c AS b ON a.cno  = b.Cno").arg(sno);
                   //query.exec(sql);
                   bool T2=true;
                   bool ok = query.exec(sql);
                   if(ok)
                   {
                       query.first();
                       if(query.value(0).isNull()==false){
                           QString credit=query.value(0).toString();
                           QString text=QString("学生编号为 %1 ，总学分为 %2 分").arg(sno).arg(credit);
                           QMessageBox::information(this ,tr("查询结果") , text);
                           T2=false;
                       }
                   }
                   else
                   {
                       QMessageBox::information(this ,tr("提示") , tr("查询失败!"));
                       T2=false;
                   }
                   if(T2==true)
                       QMessageBox::information(this ,tr("提示") , tr("该编号不存在，无法查询"));
               }
