#include "espeakvoice.h"

EspeakVoice::EspeakVoice(QString language, QString name)
{
    this->_language = language;
    this->_name = name;
}

QString EspeakVoice::language()
{
    return _language;
}

void EspeakVoice::setLanguage(QString value)
{
    this->_language = value;
}

QString EspeakVoice::name()
{
    return _name;
}

void EspeakVoice::setName(QString value)
{
    this->_name = value;
}
