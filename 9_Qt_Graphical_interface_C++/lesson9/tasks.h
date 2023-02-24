#ifndef TASKS_H
#define TASKS_H

#include <QObject>
#include <QList>
#include <QString>
#include <QDate>

class Tasks : public QObject
{
    Q_OBJECT
public:
    explicit Tasks(QObject *parent = nullptr);
    void addTasks();
    ~Tasks();
signals:
    void addedNewTask();
private:
    QList<QString> *tasks;
    QList<QDate> *date;
    void writingFile();
    void readingFile() const;
};

#endif // TASKS_H
