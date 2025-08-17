#ifndef ESPEAKSAVER_H
#define ESPEAKSAVER_H

#include "espeakrunner.h"
#include "espeakvoice.h"

class EspeakSaver
{
private:
    EspeakRunner* runner;
public:
    EspeakSaver();
    ~EspeakSaver();
    void save(QString text, EspeakVoice* voice, int amplitude, int pitch, QString filename);
};

#endif // ESPEAKSAVER_H
