#include "optionsloader.h"
#include "options_filename.h"
#include "espeakvoice.h"

#include <QJsonObject>

OptionsLoader::OptionsLoader()
{
    this->fileLoader = new FileLoader(OPTIONS_FILENAME);
}

OptionsLoader::~OptionsLoader()
{
    delete this->fileLoader;
}


Options* OptionsLoader::load()
{
    QString jsonString = fileLoader->load();
    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    QJsonObject obj = doc.object();
    QJsonObject voiceObj = obj["voice"].toObject();
    EspeakVoice* voice = new EspeakVoice(voiceObj["language"].toString(), voiceObj["name"].toString());

    return new Options(voice, obj["amplitude"].toInt(), obj["pitch"].toInt());
}
