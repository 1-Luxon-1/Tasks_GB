#include "tasks.h"

Tasks::Tasks(QObject *parent)
    : QObject{parent}
{
    readingBD();
}

Tasks::~Tasks()
{

}

void Tasks::addTasks(QString task, QString dat, QString prog)
{
    QSqlQuery query;
    QString str = "INSERT INTO taskList (task, date, progress)"
                  "VALUES('%1', '%2', '%3');";
    QString q = str.arg(task).arg(dat).arg(prog);
    if(!query.exec(q))
    {
        qDebug() << "Unable to make insert operation";
        return;
    }
}

int Tasks::getNumTasks()
{
    QSqlQuery query;
    if(!query.exec("SELECT * FROM tasksList;"))
    {
        qDebug() << "Unable to read table";
    }

    QSqlRecord rec = query.record();
    while(query.next())
    {
        if(query.next() == query.last())
        {
            return query.value(rec.indexOf("id")).toInt();
        }
    }
}

//void Tasks::printTable()
//{
//    QSqlQuery query;
//    if(!query.exec("SELECT * FROM tasksList;"))
//    {
//        qDebug() << "Unable to read table";
//    }

//    QSqlRecord rec = query.record();
//    while(query.next())
//    {
//        qDebug() << query.value(rec.indexOf("id")).toInt()<<"\t"<<
//                    query.value(rec.indexOf("task")).toString()<<"\t"<<
//                    query.value(rec.indexOf("date")).toString()<<"\t"<<
//                    query.value(rec.indexOf("progress")).toString();
//    }
//}


void Tasks::readingBD()
{
    QSqlQuery query;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tasksList.db");
    if(!db.open())
    {
        qDebug() << "Unable to connect table";
    }

    if(!query.exec("CREATE TABLE tasksList ("
                   "id INTEGER PRIMARY KEY NOT NULL,"
                   "task VARCHAR(30),"
                   "date VARCHAR(11),"
                   "progress VARCHAR(2))"))
    {
        qDebug() << "Unable to create table";
        return;
    }
}
