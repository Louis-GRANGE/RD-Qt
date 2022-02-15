#include "cobject.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include "collision.h"

CObject::CObject()
{
    transform = Transform();
    drawObject = cDrawObject();

    qDebug() << "Init: " << Singleton<GLDisplayWidget>::getInstance().assets.size();
    Singleton<GLDisplayWidget>::getInstance().AddCObject(this);
}

CObject::~CObject()
{
    //transform.Move(QVector3D(100,100,100));
}

modele CObject::getDataMesh(QString path)
{
    modele toReturn;

    std::vector<QVector3D> vertices;
    std::vector<int> triangles;

    std::vector<QVector3D> colors = {QVector3D(1,1,1)};

    QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            vertices = {
                    QVector3D(-0.5,0.8,0),
                    QVector3D(0,1.6,0),
                    QVector3D(0.5,0.8,0)
                } ;

            triangles = {0, 1, 2};

            colors = {QVector3D(1,0,1)};

            toReturn = {vertices, triangles, colors};
            return toReturn;
        }

        else
        {
            QTextStream in(&file);
            QString line = in.readLine();
            QStringList splittedLine;

            while (!line.isNull()) {
                //process_line(line);
                line = in.readLine();

                splittedLine = line.split(" ");
                if(splittedLine[0] == "v")
                {
                    QVector3D newVertice = {splittedLine[1].toFloat(), splittedLine[2].toFloat(), splittedLine[3].toFloat()};
                    vertices.push_back(newVertice);
                }
                else if(splittedLine[0] == "f")
                {
                    triangles.push_back(splittedLine[1].split("/")[0].toInt());
                    triangles.push_back(splittedLine[2].split("/")[0].toInt());
                    triangles.push_back(splittedLine[3].split("/")[0].toInt());
                }
            }
            toReturn = {vertices, triangles, colors};
            return toReturn;
        }
}

