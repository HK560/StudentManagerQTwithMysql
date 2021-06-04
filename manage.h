#ifndef MANAGE_H
#define MANAGE_H

#include <QWidget>

namespace Ui {
class manage;
}

class manage : public QWidget
{
    Q_OBJECT

public:
    explicit manage(QWidget *parent = nullptr);
    ~manage();

private:
    Ui::manage *ui;


private slots:
    void on_pushButton_9_clicked();

    void on_manage_adminButton_clicked();

    void on_stu_inform_guanlipushButton_clicked();

    void on_manage_gradepushButton_clicked();

    void on_course_manageButton_clicked();

    void on_manage_teacherBtn_clicked();
    void on_pushButton_5_clicked();
};

#endif // MANAGE_H
