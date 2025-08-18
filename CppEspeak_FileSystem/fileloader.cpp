#include "fileloader.h"

#include <QFile>

FileLoader::FileLoader(QString filename)
{
    this->filename = filename;
}

QString FileLoader::load()
{
    QString result = "";

    QFile file = QFile(filename);
    file.open(QIODevice::ReadOnly);
    result = QString(file.readAll());
    file.close();

    return result;
}
