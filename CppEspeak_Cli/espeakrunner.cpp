#include "espeakrunner.h"

EspeakRunner::EspeakRunner(QString espeakPath)
{
    this->espeakPath = espeakPath;
}

QProcess* EspeakRunner::runAndWaitForFinished(QStringList args)
{
    QProcess* process = new QProcess();
    process->setProgram(this->espeakPath);
    process->setArguments(args);
    process->start();
    process->waitForFinished(3000);

    return process;
}

QString EspeakRunner::runAndCaptureOutput(QStringList args)
{
    QProcess* process = runAndWaitForFinished(args);

    QByteArray stdOutBytes = process->readAllStandardOutput();
    QString stdOut = QString(stdOutBytes.data());
    delete process;

    return stdOut;
}

QProcess* EspeakRunner::runAndReturnProcess(QStringList args)
{
    QProcess* process = new QProcess();
    process->setProgram(this->espeakPath);
    process->setArguments(args);
    process->start();

    return process;
}
