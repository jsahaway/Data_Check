#include "myapp.h"
#include <QDebug>

using namespace std;

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
    if(myBDD.userIsConnect()){
        QStringList blop = myBDD.displaySQLQuery("SELECT * FROM gare;");
        QList<QObject*> dataList;
        dataList.append(new MyBind( blop ));

        if( m_context!= nullptr )
            m_context->setContextProperty("myModel", QVariant::fromValue( dataList ));
        else
            qDebug() << "Context non instancié";
    } else {

        Table myCSV;
        myCSV.loadData("files/example_gares.csv");

        QStringList listToQml;
        //listToQml << "item1" << "item2" << "item3";
        listToQml = myCSV.getDataBaseQT();



        QList<QObject*> dataList;
        dataList.append(new MyBind( listToQml ));



        if( m_context!= nullptr )
            m_context->setContextProperty("myModel", QVariant::fromValue( dataList ));
        else
            qDebug() << "Context non instancié";



    }
}
