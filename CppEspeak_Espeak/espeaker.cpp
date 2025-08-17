#include "espeaker.h"

#include "espeakrunnerfactory.h"

Espeaker::Espeaker()
{
    this->runner = EspeakRunnerFactory::get();
}

Espeaker::~Espeaker()
{
    delete this->runner;
}


QProcess* Espeaker::speak(QString text, EspeakVoice* voice, int amplitude, int pitch)
{
    QStringList args = QStringList();
    args.append("-v");
    args.append(voice->language());
    args.append("-a");
    args.append(QString::number(amplitude));
    args.append("-p");
    args.append(QString::number(pitch));
    args.append(text);
    return runner->runAndReturnProcess(args);
}
