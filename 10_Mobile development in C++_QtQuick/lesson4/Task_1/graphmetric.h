#ifndef GRAPHMETRIC_H
#define GRAPHMETRIC_H

#include <QObject>
#include <QList>
#include <QtMath>

class GraphMetric : public QObject
{
    Q_OBJECT
public:
    explicit GraphMetric(QObject *parent = nullptr);

    enum graphsTypes
    {
        ySin,
        yx,
        yx25,
        yxpow2,
        ylog2x
    };

private:
    QString grColor;
    QList<double> *x;
    QList<double> *y;
    graphsTypes typGraph;
    Q_ENUM(graphsTypes)

public:
    Q_INVOKABLE void changeGraphType(graphsTypes);

    Q_INVOKABLE double getX(int in);

    Q_INVOKABLE double getY(int in);

};

#endif // GRAPHMETRIC_H
