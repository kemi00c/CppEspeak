#ifndef ESPEAKRUNNER_H
#define ESPEAKRUNNER_H

#include <QString>
#include <QProcess>

class EspeakRunner
{
private:
    QString espeakPath;
public:
    EspeakRunner(QString espeakPath);
    QProcess* runAndWaitForFinished(QStringList args);
    QString runAndCaptureOutput(QStringList args);
    QProcess* runAndReturnProcess(QStringList args);
};

#endif // ESPEAKRUNNER_H
