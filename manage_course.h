#ifndef MANAGE_COURSE_H
#define MANAGE_COURSE_H

#include <QWidget>

namespace Ui {
class manage_course;
}

class manage_course : public QWidget
{
    Q_OBJECT

public:
    explicit manage_course(QWidget *parent = nullptr);
    ~manage_course();

private slots:
    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void on_updateButton_clicked();
    void on_seeAllButton_clicked();
    void on_backButton_clicked();

private:
    Ui::manage_course *ui;
    QStringList headers;
};

#endif // MANAGE_COURSE_H
