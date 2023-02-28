#ifndef TASKS_H
#define TASKS_H

#include <QObject>
#include <QList>
#include <QString>
#include <QDate>
#include <QFile>

class Tasks : public QObject
{
    Q_OBJECT
public:
    explicit Tasks(QObject *parent = nullptr);
    Q_INVOKABLE void addTasks(QString str, QString dat, QString prog);
    Q_INVOKABLE int getNumTasks();
    ~Tasks();
private:
    QList<QString> *tasks;
    QList<QDate> *date;
    QList<int> *progress;
    void writingFile();
    void readingFile();

    int numTasks;
};

#endif // TASKS_H
