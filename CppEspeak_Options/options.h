#ifndef OPTIONS_H
#define OPTIONS_H

#include <QJsonDocument>
#include "espeakvoice.h"

class Options
{
private:
    EspeakVoice* _voice;
    int _amplitude;
    int _pitch;
public:
    Options(EspeakVoice* voice, int amplitude, int pitch);

    EspeakVoice* voice();
    void setVoice(EspeakVoice* value);

    int amplitude();
    void setAmplitude(int value);

    int pitch();
    void setPitch(int value);

    QJsonDocument toJson();

    static Options fromJson(QJsonDocument json);

    static Options* getDefault();
};

#endif // OPTIONS_H
