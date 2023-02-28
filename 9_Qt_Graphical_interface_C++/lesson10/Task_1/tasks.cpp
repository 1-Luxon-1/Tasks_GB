#include "tasks.h"

Tasks::Tasks(QObject *parent)
    : QObject{parent}
{
    numTasks = 0;
    readingFile();
}

Tasks::~Tasks()
{
   writingFile();
}

void Tasks::addTasks(QString str, QString dat, QString prog)
{
    tasks->append(str);
    date->append(QDate::fromString(dat, "dd.mm.yyyy"));
    progress->append(prog.toInt(nullptr, 10));
    numTasks++;
}

int Tasks::getNumTasks()
{
    return numTasks;
}


void Tasks::writingFile()
{
    QFile writeFile(":/files/MyTasks.txt");
    if(writeFile.open(QIODevice::WriteOnly))
    {
        QString text="";
        QByteArray ba;
        for(int i=0; i<(int)(progress->size()); i++)
        {
            text += tasks->at(i);
            text += '\n';
            text += date->at(i).toString();
            text += '\n';
            text += QString::number(progress->at(i));
            text += '\n';
        }
        ba = text.toUtf8();
        writeFile.write(ba, ba.length());
        writeFile.close();
    }
}

void Tasks::readingFile()
{
    tasks = new QList<QString>;
    date = new QList<QDate>;
    progress = new QList<int>;

    QFile readFile(":/files/MyTasks.txt");
    if(readFile.open(QIODevice::ReadOnly))
    {
        QByteArray ba = readFile.readAll();
        QString text(ba);
        QString tempText="";
        int flag = 1;
        for(int i = 0; i<text.length();i++)
        {
            if(text[i]=='\n' && flag%3==0)
            {
                progress->append(tempText.toInt(nullptr, 10));
                flag++;
                tempText.clear();
            }
            else if(text[i]=='\n' && flag%2==0)
            {
                date->append(QDate::fromString(tempText, "dd.mm.yyyy"));
                flag++;
                tempText.clear();
            }
            else if(text[i]=='\n')
            {
                tasks->append(tempText);
                flag++;
                tempText.clear();
                numTasks++;
            }
            tempText += text[i];
        }
        readFile.close();
    }
}
