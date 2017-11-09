#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>
#include <QVariant>

#include "myapp.h"
#include "sqluser.h"


using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext* ctx = engine.rootContext(); 
    MyApp myApp;

    myApp.setContext( ctx );
    myApp.updateContext();

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty()) { return -1; }


    return app.exec();
}
