#ifndef GLOBLE_CPP
#define GLOBLE_CPP
#include "globle.h"

//globle::globle()
//{

//}
QString dataBaseName = "SC_pro";
QString username_qj = "";
QString password_qj = "";
QVariantList list_all_student;
QString sqluser="root";
QString sqlpass="023168";
QVariantList list_all_dormstudent;

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

// Open the Database
bool openDatabase()
{
    db.setHostName("localhost");
    db.setDatabaseName(dataBaseName);
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    db.setPort(3306);

    if (!db.open())
        return false;

    return true;
}

// Close Database
void closeDatabase()
{
    db.close();
}



#endif // VARIATE_H
