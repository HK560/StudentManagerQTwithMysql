#include "manage.h"
#include "ui_manage.h"
#include"globle.h"
#include"mainwindow.h"
#include "manage_admin.h"
#include "manage_student.h"
#include "manage_grade.h"
#include "manage_course.h"
#include "manage_teacher.h"


manage::manage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manage)
{
    ui->setupUi(this);
}

manage::~manage()
{
    delete ui;
}



void manage::on_pushButton_9_clicked()
{
    MainWindow *dh;
    //this->hide();
    dh=new MainWindow  ;

    dh->show();
}

void manage::on_manage_adminButton_clicked()
{
    //this->hide();
    manage_admin *ti=new manage_admin;
    ti->show();
}

void manage::on_stu_inform_guanlipushButton_clicked()
{
    //this->hide();
    manage_student *ij=new manage_student;
    ij->show();
}



void manage::on_manage_gradepushButton_clicked()
{
    //this->hide();
    manage_grade *pk=new manage_grade;
    pk->show();

}

void manage::on_course_manageButton_clicked()
{
    //this->hide();
    manage_course *ew=new manage_course;
    ew->show();
}



void manage::on_manage_teacherBtn_clicked()
{
    //this->hide();
    manage_teacher *vw=new manage_teacher;
    vw->show();
}

void manage::on_pushButton_5_clicked()
{
    this->hide();
    MainWindow *cc=new MainWindow;
    cc->show();
}
