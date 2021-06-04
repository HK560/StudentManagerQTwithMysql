#include "manage_teacher.h"
#include "ui_manage_teacher.h"
#include "manage.h"
#include "globle.h"

manage_teacher::manage_teacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manage_teacher)
{
    ui->setupUi(this);
    //ui->seeAllButton->hide();
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    headers<<"编号"<<"姓名"<<"职务"<<"工资"<<"课程";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(100);
    on_seeAllButton_clicked();
}

manage_teacher::~manage_teacher()
{
    delete ui;
}

void manage_teacher::on_seeAllButton_clicked()
{
    QSqlQuery query;

    query.exec("select * from t");
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    int row=0;
    while(query.next())
    {
        for(int i  = 0 ; i <5; i++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(query.value(i).toString());
            ui->tableWidget->setItem(row, i, item);
        }
        row++;
    }

}

void manage_teacher::on_insertButton_clicked()
{
    QString id=ui->tnoEdit->text();
    QString username=ui->tnameEdit->text();
    QString work=ui->tworkEdit->text();
    QString wage=ui->twageEdit->text();
    QString course=ui->tcourseEdit->text();
   // QString password=ui->passwardLineEdit->text();

    QSqlQuery query;
    query.exec("select tno from t");
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
        sql = QString("insert into t  VALUES ('%1', '%2', '%3','%4','%5')")
                .arg(id).arg(username).arg(work).arg(wage).arg(course);


        bool ok = query.exec(sql);
        if(ok)
            QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
        else
            QMessageBox::information(this ,tr("提示") , tr("添加失败!"));

    }
    on_seeAllButton_clicked();
}

void manage_teacher::on_deleteButton_clicked()
{
    QString id=ui->tnoEdit->text();

    QSqlQuery query;
    query.exec("select tno from t");
    bool T2=true;
    while(query.next())
    {
        QString id1= query.value(0).toString();

        if(id.compare(id1)==0)
        {
            QString sql;
            sql = QString("DELETE FROM t "
                          " where tno = '%1' ").arg(id);

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

void manage_teacher::on_updataButton_clicked()
{
    QString id=ui->tnoEdit->text();
    QString username=ui->tnameEdit->text();
    QString work=ui->tworkEdit->text();
    QString wage=ui->twageEdit->text();
    QString course=ui->tcourseEdit->text();

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
                            .arg(id).arg(username).arg(work).arg(wage).arg(course);

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
    if(T2==false)
        QMessageBox::information(this ,tr("提示") , tr("该编号不存在，无法更改"));

    on_seeAllButton_clicked();
}

void manage_teacher::on_backButton_clicked()
{
   // manage *dh;
    this->hide();
    //dh=new manage ;
   // dh->show();
}

void manage_teacher::on_tworkSearchBtn_1_clicked()
{
    QString tworkname=ui->tworkSearchEdit_1->text();

    QSqlQuery query;
    QString sql=QString("select member FROM((select  twork,COUNT(*)as member from t GROUP BY twork)as a) where twork='%1'").arg(tworkname);
    //query.exec(sql);
    bool T2=true;
    bool ok = query.exec(sql);
    if(ok)
    {
        query.first();
        if(query.value(0).isValid()!=0){
            QString member=query.value(0).toString();
            QString text=QString("职务为 %1 的人员数量为 %2 位").arg(tworkname).arg(member);
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
        QMessageBox::information(this ,tr("提示") , tr("该编号不存在，无法更改"));
}

void manage_teacher::on_tworkSearchBtn_2_clicked()
{
    QString tworkname=ui->tworkSearchEdit_2->text();

    QSqlQuery query;
    QString sql=QString("SELECT AVG FROM (select twork,AVG(twage)as AVG FROM t GROUP BY twork)as a WHERE twork='%1'").arg(tworkname);
    //query.exec(sql);
    bool T2=true;
    bool ok = query.exec(sql);
    if(ok)
    {
        query.first();
        if(query.value(0).isValid()!=0){
            QString wage=query.value(0).toString();
            QString text=QString("职务为 %1 的平均工资为 %2 元").arg(tworkname).arg(wage);
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
        QMessageBox::information(this ,tr("提示") , tr("该编号不存在，无法更改"));
}
