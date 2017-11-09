#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include <QDebug>
#include <QString>
#include <QStringList>



class Table
{
public:
    Table();


    std::vector<std::vector<std::string> > getDataBase() const;
    void setDataBase(const std::vector<std::vector<std::string> > &dataBase);


    void seeTable (std::vector<std::vector<std::string>> & table) const;
    void seeDataBase();

    void loadData   (std::string filePath);
    void pushData   (std::vector<std::string> property);
    void sortData   ();
    void setId      (std::vector<std::string> property);
    void sortTable  (std::vector<std::string> property);

    std::vector<std::vector<std::string>> createEntity (std::vector<std::string> property);
    std::vector<std::vector<std::string>> createRelation (std::vector<std::string> property);

    void createCSV (std::string fileName, std::vector<std::vector<std::string>> & table);


    // for import string in qml
    QStringList getDataBaseQT() const;
    void setDataBaseQT(const QStringList &dataBaseQT);


private:
    QStringList m_dataBaseQT;

    int m_col;
    int m_row;

    std::vector<std::vector<std::string>> m_dataBase;
    std::vector<std::vector<std::string>> m_dataTemp; // vector to sort data
    std::vector<std::vector<std::string>> m_dataTempPrevious;


};

#endif // TABLE_H
