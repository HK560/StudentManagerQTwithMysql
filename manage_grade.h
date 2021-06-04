#ifndef MANAGE_GRADE_H
#define MANAGE_GRADE_H

#include <QWidget>

namespace Ui {
class manage_grade;
}

class manage_grade : public QWidget
{
    Q_OBJECT

public:
    explicit manage_grade(QWidget *parent = nullptr);
    ~manage_grade();

private slots:
    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void on_updateButton_clicked();
    void on_seeAllButton_clicked();
    void on_backButton_clicked();

    void on_avgGradeBtn_clicked();

    void on_maxGradeBtn_clicked();

    void on_minGradeBtn_clicked();

    void on_sumCreditBtn_clicked();

private:
    Ui::manage_grade *ui;
    QStringList headers;
};

#endif // MANAGE_GRADE_H
