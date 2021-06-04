#ifndef MANAGE_TEACHER_H
#define MANAGE_TEACHER_H

#include <QWidget>

namespace Ui {
class manage_teacher;
}

class manage_teacher : public QWidget
{
    Q_OBJECT

public:
    explicit manage_teacher(QWidget *parent = nullptr);
    ~manage_teacher();

private slots:
    void on_seeAllButton_clicked();

    void on_insertButton_clicked();

    void on_deleteButton_clicked();

    void on_updataButton_clicked();

    void on_backButton_clicked();

    void on_tworkSearchBtn_1_clicked();

    void on_tworkSearchBtn_2_clicked();

private:
    Ui::manage_teacher *ui;
    QStringList headers;
};

#endif // MANAGE_TEACHER_H
