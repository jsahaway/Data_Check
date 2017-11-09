#include "myapp.h"
#include <QDebug>


MyApp::MyApp(QObject *parent) : QObject(parent), m_context(nullptr)
{


}

void MyApp::setContext(QQmlContext *context)
{
    m_context = context;
}

// Function to update the QML
void MyApp::updateContext()
{

    SqlUser myBDD;
    myBDD.connectToDatabase("gares");
    //myBDD.executeSQLQuery("SELECT * FROM codepostal, departement, desserte;");

    if(myBDD.userIsConnect()){
        QStringList blop = myBDD.displaySQLQuery("SELECT * FROM gare;");
        QList<QObject*> dataList;
        dataList.append(new MyBind( blop ));

        if( m_context!= nullptr )
            m_context->setContextProperty("myModel", QVariant::fromValue( dataList ));
        else
            qDebug() << "Context non instancié";
    } else {

        QStringList liststr;
        liststr << "item1" << "item2" << "item3";
        QList<QObject*> dataList;
        dataList.append(new MyBind( liststr ));

        if( m_context!= nullptr )
            m_context->setContextProperty("myModel", QVariant::fromValue( dataList ));
        else
            qDebug() << "Context non instancié";



    }
}
