#include "mybind.h"

MyBind::MyBind(QObject *parent) : QObject(parent)
{

}

MyBind::MyBind(const QString &myString, QObject *parent)
    :m_myString(myString), QObject(parent)
{


}

MyBind::MyBind(const QStringList &myList, QObject *parent)
    :m_myList(myList), QObject(parent)
{


}

MyBind::MyBind(const QVariant &myVariant, QObject *parent)
    :m_myVariant(myVariant), QObject(parent)
{


}

