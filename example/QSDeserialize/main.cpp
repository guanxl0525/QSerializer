#include <QCoreApplication>
#include "../classes.h"

#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"QSDeserialize";

    qDebug()<<"\nDESERIALIZATION";
    QFile json ("../general.json");
    if(!json.exists())
        qWarning()<<"ERROR: general.json is not exist";
    if(json.open(QIODevice::ReadOnly))
    {
        // empty object
        General general;
        qDebug()<<QSerializer::toByteArray(general.toJson()).constData();

        general.fromJson(json.readAll());
        qDebug()<<QSerializer::toByteArray(general.toJson()).constData();
        json.close();
    }


    QFile xml ("../general.xml");
    if(!xml.exists())
        qWarning()<<"ERROR: general.xml is not exist";
    if(xml.open(QIODevice::ReadOnly))
    {
        // empty object
        General general;
        qDebug()<<QSerializer::toByteArray(general.toXml()).constData();

        general.fromXml(xml.readAll());
        qDebug()<<QSerializer::toByteArray(general.toXml()).constData();
        xml.close();
    }

    return a.exec();
}
