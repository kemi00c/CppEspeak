#ifndef ESPEAKER_H
#define ESPEAKER_H

#include <QProcess>
#include "espeakrunner.h"
#include "espeakvoice.h"

class Espeaker
{
private:
    EspeakRunner* runner;
public:
    Espeaker();
    ~Espeaker();
    QProcess* speak(QString text, EspeakVoice* voice, int amplitude, int pitch);
};

#endif // ESPEAKER_H
