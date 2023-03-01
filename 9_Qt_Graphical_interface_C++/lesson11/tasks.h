#ifndef TASKS_H
#define TASKS_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

class Tasks : public QObject
{
    Q_OBJECT
public:
    explicit Tasks(QObject *parent = nullptr);
    Q_INVOKABLE void addTasks(QString str, QString dat, QString prog);
    Q_INVOKABLE int getNumTasks();
//    void printTable();
    ~Tasks();
private:
    void readingBD();
    QSqlDatabase db;
};

#endif // TASKS_H
