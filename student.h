#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>
#include <QDebug>
namespace Ui {
class student;
}

class student : public QWidget
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = nullptr);
    ~student();
    void setID(QString Sno);

private slots:

    void on_backButton_clicked();
    void on_infoButton_clicked();
    void on_courseButton_clicked();
    void on_scoreButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_sumcreditBtn_clicked();

    void on_cmpcreditBtn_clicked();

private:
    Ui::student *ui;
    QString id;

    QStringList headers_info;
    QStringList headers_course;
    QStringList headers_grade;
};

#endif // STUDENT_H
