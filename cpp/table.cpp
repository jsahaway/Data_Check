#include "table.h"

using namespace std;


Table::Table()
{

}

vector<vector<string> > Table::getDataBase() const
{
    return m_dataBase;
}

void Table::setDataBase(const vector<vector<string> > &dataBase)
{
    m_dataBase = dataBase;
}




// COUT DATA ===========================================================================



void Table::seeTable(vector<vector<string> >& table) const
{
    cout << endl;
    for (auto i : table) {
        for (auto j : i) {
            cout << j << "; ";
        }
        cout << endl;
    }
    cout << endl << "table.size() = " << table.size() << endl;
}

void Table::seeDataBase()
{
    cout << endl;
    for (unsigned i = 0; i < m_dataBase.size(); ++i) {
        for (unsigned j = 0; j < m_dataBase[i].size(); ++j) {
             cout << m_dataBase[i][j] << " ; ";
        }
        cout << endl;
    }
    cout << endl << "dataBase.size() = " << m_dataBase.size() << endl;
}



// FUNCTIONS =========================================================================



//////////////////////
// LOADING CSV FILE //
//////////////////////
void Table::loadData(std::string filePath)
{

    ifstream file;
    file.open(filePath);
    string line;
    QString str;

    // Open .csv file in a vector[line][column]
    if(file.is_open()) {
        cout << filePath << endl;
        cout << "File load complete" << endl;

        while ( getline(file, line) ) {
            istringstream streamLine(line);
            string property;
            vector<string> tab;

            while ( getline(streamLine, property, ';') ) {
                tab.push_back(property);
                str = QString::fromStdString(property);
                m_dataBaseQT << str ;
            }
            m_dataBase.push_back(tab);
        }

        file.close();

    } else {
        cout << filePath << endl;
        cout << "File not load" << endl;
    }
}



///////////////
// PUSH DATA //
///////////////
void Table::pushData(vector<string> property)
{
    for (unsigned i = 0; i < m_dataBase.size(); ++i) {
        vector<string> tempData;
        for (unsigned j = 0; j < m_dataBase[0].size(); ++j) {
            for(unsigned k = 0; k < property.size(); k++) {
                if ( property[k] == m_dataBase[0][j] ) {
                    tempData.push_back(m_dataBase[i][j]);
                }
            }
        }
        m_dataTemp.push_back(tempData);
    }

    // Save the datas to make prk
    m_dataTempPrevious = m_dataTemp;
}



///////////////
// SORT DATA //
///////////////
void Table::sortData()
{
    // Sort data per line
    sort (m_dataTemp.begin()+1, m_dataTemp.end());
    m_dataTemp.erase (unique(m_dataTemp.begin(), m_dataTemp.end()), m_dataTemp.end());
}



/////////////////////////
// SET PRK IN DATABASE //
/////////////////////////
void Table::setId(vector<string> property)
{

    // Find equality between data and push_back in m_dataBase
    for (unsigned i = 0; i < m_dataTemp.size(); ++i) {
        for (unsigned j = 0; j < m_dataTempPrevious.size(); ++j) {
            if(m_dataTemp[i] == m_dataTempPrevious[j]) {
                if (j == 0) {
                    m_dataBase[j].push_back(property[0]);
                } else {
                    m_dataBase[j].push_back(to_string(i));
                }
            }
        }
    }
}



/////////////
// SET ID  //
/////////////
void Table::sortTable(vector<string> property)
{
    vector<vector<string>> saveDataTemp = m_dataTemp;
    m_dataTemp.clear();

    for (unsigned i = 0; i < saveDataTemp.size(); ++i) {
        vector<string> tempData;

        for (unsigned j = 0; j < property.size(); ++j) {
            if (i == 0){
                tempData.push_back(property[j]);
            } else if (j == 0) {
                tempData.push_back(to_string(i)); // Generate id

            } else {
                tempData.push_back(saveDataTemp[i][j-1]);
            }
        }
        m_dataTemp.push_back(tempData);
    }
}



// CREATE TABLE ========================================================================



/////////////////////////
// CREATE ENTITY TABLE //
/////////////////////////
vector<vector<string> > Table::createEntity(vector<string> property)
{
    pushData(property);
    sortData();
    setId(property);
    sortTable(property);

    vector<vector<string>> newData = m_dataTemp;

    m_dataTemp.clear();
    m_dataTempPrevious.clear();

    return newData;
}



///////////////////////////
// CREATE RELATION TABLE //
///////////////////////////
vector<vector<string> > Table::createRelation(vector<string> property)
{
    pushData(property);
    sortData();

    vector<vector<string>> newData = m_dataTemp;

    m_dataTemp.clear();
    m_dataTempPrevious.clear();

    return newData;
}



// WRITE TABLE IN CSV FILE ===================================================================



/////////////////////
// WRITE CSV TABLE //
/////////////////////
void Table::createCSV(string fileName, vector<vector<string> >& table)
{
    ofstream file(fileName, ios::out | ios::trunc);

    if(file && table[0].size() > 0)
    {
        for (unsigned i = 0; i < table.size(); ++i) {
            for (unsigned j = 0; j < table[i].size(); ++j) {
                file << table[i][j];
                if( j <= table[i].size() - 2 ){
                    file << ";" ;
                }
            }
            file << endl;
        }
        file.close();
        cout << endl << "Write file " << fileName << " complete"<< endl;

    } else {
        cout << endl <<  "Error with file" << endl;
    }

}

QStringList Table::getDataBaseQT() const
{
    return m_dataBaseQT;
}

void Table::setDataBaseQT(const QStringList &dataBaseQT)
{
    m_dataBaseQT = dataBaseQT;
}
