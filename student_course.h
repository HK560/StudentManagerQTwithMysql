#ifndef STUDENT_COURSE_H
#define STUDENT_COURSE_H

#include <QWidget>

namespace Ui {
class student_course;
}

class student_course : public QWidget
{
    Q_OBJECT

public:
    explicit student_course(QWidget *parent = nullptr);
    ~student_course();

    void setID(QString id);

private slots:
    void on_selectBtn_clicked();

    void on_outBtn_clicked();



private:
    Ui::student_course *ui;
    QString ID;

    QStringList  header;
};

#endif // STUDENT_COURSE_H
