#include "options.h"
#include "espeakvoices.h"

#include <QJsonObject>

Options::Options(EspeakVoice* voice, int amplitude, int pitch)
{
    this->_voice = voice;
    this->_amplitude = amplitude;
    this->_pitch = pitch;
}

EspeakVoice* Options::voice()
{
    return _voice;
}
void Options::setVoice(EspeakVoice* value)
{
    _voice = value;
}

int Options::amplitude()
{
    return _amplitude;
}

void Options::setAmplitude(int value)
{
    _amplitude = value;
}

int Options::pitch()
{
    return _pitch;
}
void Options::setPitch(int value)
{
    _pitch = value;
}

Options* Options::getDefault()
{
    EspeakVoices espeakVoices = EspeakVoices();

    QList<EspeakVoice*>* voiceList = espeakVoices.getVoices();

    EspeakVoice* voice = NULL;

    for (EspeakVoice* item : *voiceList)
    {
        if (item->language() == "en-us")
        {
            voice = item;
            break;
        }
    }

    return new Options(voice, 100, 50);
}

QJsonDocument Options::toJson()
{
    QJsonDocument doc = QJsonDocument();
    QJsonObject object = QJsonObject();
    QJsonObject voiceObj = QJsonObject();
    voiceObj["language"] = voice()->language();
    voiceObj["name"] = voice()->name();
    object["voice"] = voiceObj;
    object["amplitude"] = amplitude();
    object["pitch"] = pitch();

    doc.setObject(object);

    return doc;
}

Options Options::fromJson(QJsonDocument json)
{
    QJsonObject object = json.object();

    QJsonObject voiceObj = object["voice"].toObject();
    EspeakVoice* jsonVoice = new EspeakVoice(voiceObj["language"].toString(), voiceObj["name"].toString());

    return Options(jsonVoice, object["amplitude"].toInt(), object["pitch"].toInt());
}
