#include "sqluser.h"

using namespace std;



SqlUser::SqlUser()
{

}

void SqlUser::connectToDatabase(const QString &nameDataBase)
{

    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setDatabaseName(nameDataBase);
    m_db.setHostName("localhost");
    m_db.setUserName("root");
    m_db.setPassword("afpa");


    if (m_db.open())
    {
        qDebug() << "connexion etablie à " << nameDataBase;
        m_isConnect = true;
    }

    else
    {
        qDebug() << "echec de la connexion" << endl;
        qDebug() << "erreur : " << (m_db.lastError().text()) << endl;
        m_isConnect = false;
    }
}

void SqlUser::newDatabase(const QString &nameDataBase)
{
    QSqlQuery query("CREATE DATABASE IF NOT EXISTS " + nameDataBase);

    if (query.exec())
    {
        qDebug() << "la BDD " + nameDataBase + " a ete cree" << endl;
    }

    else
    {
        qDebug() << "erreur : " << (query.lastError().text())<< endl;
    }
}

void SqlUser::deleteDatabase(const QString &nameDataBase)
{
    QSqlQuery query("DROP DATABASE " + nameDataBase);

    if (query.exec())
    {
        qDebug() << "la BDD " + nameDataBase + " a ete supprimee" << endl;
    }

    else
    {
        qDebug() << "erreur : " << (query.lastError().text())<< endl;
    }
}

//execution d'une requete sql depuis une TextArea
void SqlUser::executeSQLQuery(QString &script)
{
    script.remove('\n');
    script.remove("`");

    QSqlQuery query;
    if (query.exec(script))
    {
        qDebug() << "requete executée";
    }

    else
    {
        qDebug() << "erreur : " << (query.lastError().text())<< endl;
    }
}

//Pour affichage des resultats de la requete
QStringList SqlUser::displaySQLQuery(QString script)
{
    QStringList sl;
    QSqlQuery query;
    QSqlQueryModel model;
    model.setQuery(script);

    for (int i(0) ; i < model.rowCount(); i++)
    {
        QString ligne1 = model.record(i).value(0).toString();
        for (int j(1) ; j < model.columnCount() ; j++)
        {
            QString ligne2 = model.record(i).value(j).toString();
            ligne1.append("\t" + ligne2);
            sl <<  ligne2 ;
        }
        //sl << ligne1;
    }

    return sl;
}

bool SqlUser::userIsConnect()
{
    return m_isConnect;
}



