#include "graphmetric.h"

GraphMetric::GraphMetric(QObject *parent)
    : QObject{parent}
{
    grColor = "black";
    x = new QList<double>;
    y = new QList<double>;
    typGraph = yx;
    for(double i = 0.0; i < 5.0; i+=0.1)
    {
        x->append(i);
    }
    int i = 0;
    while(y->size() != x->size())
    {
        y->append(x->at(i));
        i++;
    }
}

double GraphMetric::getX(int in)
{
    return x->at(in);
}

double GraphMetric::getY(int in)
{
    return y->at(in);
}

void GraphMetric::changeGraphType(graphsTypes gt)
{
    if(gt != typGraph)
    {
        typGraph = gt;
        if(gt == ySin)
        {

        }
        if(typGraph == graphsTypes::ySin)
        {
            int i = 0;
            y->clear();
            while(i != x->size())
            {
                y->append(qSin(x->at(i)));
                i++;
            }
        }
        else if(typGraph == yx)
        {
            int i = 0;
            y->clear();
            while(i != x->size())
            {
                y->append(x->at(i));
                i++;
            }
        }
        else if(typGraph == yx25)
        {
            int i = 0;
            y->clear();
            while(i != x->size())
            {
                y->append(qFabs(x->at(i)-2.5));
                i++;
            }
        }
        else if(typGraph == yxpow2)
        {
            int i = 0;
            y->clear();
            while(i != x->size())
            {
                y->append(qPow(x->at(i),2));
                i++;
            }
        }
        else if(typGraph == ylog2x)
        {
            int i = 0;
            y->clear();
            while(i != x->size())
            {
                y->append(qLn(x->at(i))/qLn(2));
                i++;
            }
        }
    }
}
