#ifndef MANAGE_ADMIN_H
#define MANAGE_ADMIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <globle.h>
#include <QtDebug>

namespace Ui {
class manage_admin;
}

class manage_admin : public QWidget
{
    Q_OBJECT

public:
    explicit manage_admin(QWidget *parent = nullptr);
    ~manage_admin();


private slots:

    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void on_updateButton_clicked();
    void on_seeAllButton_clicked();
    void on_backButton_clicked();

private:
    Ui::manage_admin *ui;
    QStringList headers;
};

#endif // MANAGE_ADMIN_H
