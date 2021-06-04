#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <QWidget>

namespace Ui {
class student_info;
}

class student_info : public QWidget
{
    Q_OBJECT

public:
    explicit student_info(QWidget *parent = nullptr);
    ~student_info();
    void setID(QString idname);

private slots:
    void on_pushButton_clicked();

private:
    Ui::student_info *ui;
    QString ID;
};

#endif // STUDENT_INFO_H
