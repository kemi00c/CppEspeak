#ifndef ESPEAKVOICE_H
#define ESPEAKVOICE_H

#include <QString>

class EspeakVoice
{
private:
    QString _language;
    QString _name;
public:
    EspeakVoice(QString language, QString name);
    QString language();
    void setLanguage(QString value);
    QString name();
    void setName(QString value);

};

#endif // ESPEAKVOICE_H
