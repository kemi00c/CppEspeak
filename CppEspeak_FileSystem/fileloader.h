#ifndef FILELOADER_H
#define FILELOADER_H

#include <QString>

class FileLoader
{
private:
    QString filename;
public:
    FileLoader(QString filename);

    QString load();
};

#endif // FILELOADER_H
