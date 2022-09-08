#ifndef TRAINTHREAD_V1_H
#define TRAINTHREAD_V1_H

#include <QObject>
#include <QVector>

class trainThread_v1 : QObject{
    Q_OBJECT
public:
    trainThread_v1();
    ~trainThread_v1();


    struct point{
      QString   name;
      double    longitude;
      double    latitude;
      double    temperature;
      double    humidity;              //%
      QVector<double>   distance;
    };
    void generatePoint(int countPoint);
    QVector<struct> PointVect;


private:

};


#endif // TRAINTHREAD_V1_H
