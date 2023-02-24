#include "tasks.h"

Tasks::Tasks(QObject *parent)
    : QObject{parent}
{
    tasks = new QList<QString>;
    date = new QList<QDate>;
}

Tasks::~Tasks()
{

}

void Tasks::addTasks()
{

}

void Tasks::writingFile()
{

}

void Tasks::readingFile() const
{

}
