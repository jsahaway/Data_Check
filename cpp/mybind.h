#ifndef MYBIND_H
#define MYBIND_H

#include <QObject>
#include <QVariant>
#include <QStringList>

class MyBind : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString myString READ myString WRITE setmyString NOTIFY myStringChanged)
    Q_PROPERTY(QStringList myList READ myList WRITE setMyList NOTIFY myListChanged)
    Q_PROPERTY(QVariant myVariant READ myVariant WRITE setMyVariant NOTIFY myVariantChanged)

public:
    explicit MyBind(QObject *parent = nullptr);
    MyBind(const QString &myString, QObject *parent=0);
    MyBind(const QStringList &myList, QObject *parent=0);
    MyBind(const QVariant &myVariant, QObject *parent=0);



    QString myString() const
    {
        return m_myString;
    }

    QStringList myList() const
    {
        return m_myList;
    }

    QVariant myVariant() const
    {
        return m_myVariant;
    }

signals:
    void myStringChanged(QString myString);

    void myListChanged(QStringList myList);

    void myVariantChanged(QVariant myVariant);


public slots:
    void setmyString(QString myString)
    {
        if (m_myString == myString)
            return;

        m_myString = myString;
        emit myStringChanged(m_myString);
    }

    void setMyList(QStringList myList)
    {
        if (m_myList == myList)
            return;

        m_myList = myList;
        emit myListChanged(m_myList);
    }

    void setMyVariant(QVariant myVariant)
    {
        if (m_myVariant == myVariant)
            return;

        m_myVariant = myVariant;
        emit myVariantChanged(m_myVariant);
    }



private :

private:
    QString m_myString;
    QStringList m_myList;
    QVariant m_myVariant;

};

#endif // MYBIND_H
