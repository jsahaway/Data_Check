#ifndef SQLUSER_H
#define SQLUSER_H

#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>

#include <iostream>
#include <QString>
#include <QDebug>

class SqlUser
{

public:

    SqlUser();



    void connectToDatabase(const QString &nameDataBase = "");
    void newDatabase(const QString &nameDataBase);
    void deleteDatabase(const QString &nameDataBase);

    void executeSQLQuery(QString &script);
    QStringList displaySQLQuery(QString script);

    bool userIsConnect();
private :

    //attributs
    QSqlDatabase m_db;
    bool m_isConnect = false;

};

#endif // SQLUSER_H
