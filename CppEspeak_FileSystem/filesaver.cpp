#include "filesaver.h"

#include <QFile>

FileSaver::FileSaver(QString filename)
{
    this->filename = filename;
}

void FileSaver::save(QString data)
{
    QFile file = QFile(filename);
    file.open(QIODevice::WriteOnly);
    file.write(data.toUtf8());
    file.close();
}
