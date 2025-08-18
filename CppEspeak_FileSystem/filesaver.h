#ifndef FILESAVER_H
#define FILESAVER_H

#include <QString>

class FileSaver
{
private:
    QString filename;
public:
    FileSaver(QString filename);
    void save(QString data);
};

#endif // FILESAVER_H
