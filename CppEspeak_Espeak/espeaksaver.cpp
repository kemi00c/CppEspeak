#include "espeaksaver.h"

#include "espeakrunnerfactory.h"

EspeakSaver::EspeakSaver()
{
    runner = EspeakRunnerFactory::get();
}

EspeakSaver::~EspeakSaver()
{
    delete runner;
}

void EspeakSaver::save(QString text, EspeakVoice* voice, int amplitude, int pitch, QString filename)
{
    QStringList args = QStringList();
    args.append("-w");
    args.append(filename);
    args.append("-v");
    args.append(voice->name());
    args.append("-a");
    args.append(QString::number(amplitude));
    args.append("-p");
    args.append(QString::number(pitch));
    args.append(text);
    runner->runAndWaitForFinished(args);
}
