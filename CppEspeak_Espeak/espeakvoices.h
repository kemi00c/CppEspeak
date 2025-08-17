#ifndef ESPEAKVOICES_H
#define ESPEAKVOICES_H

#include <QList>
#include "espeakvoice.h"

#include "espeakrunner.h"

class EspeakVoices
{
private:
    EspeakRunner* runner;
public:
    EspeakVoices();
    ~EspeakVoices();
    QList<EspeakVoice*>* getVoices();
};

#endif // ESPEAKVOICES_H
