#include "espeakvoices.h"

#include <QRegularExpression>
#include "espeakrunnerfactory.h"
#include "espeakvoice.h"

static const QString LANGUAGE_REGEX = R"(^\s*\d+\s*(?<language>[a-zA-Z0-9\-]{2,})\s*[MF\-\/]*\s*(?<name>[A-Za-z0-9\-\(\)_]+).*$)";

EspeakVoices::EspeakVoices()
{
    this->runner = EspeakRunnerFactory::get();
}

EspeakVoices::~EspeakVoices()
{
    delete this->runner;
}

QList<EspeakVoice*>* EspeakVoices::getVoices()
{
    QString output = runner->runAndCaptureOutput(QStringList("--voices"));
    QStringList lines = output.split('\n');
    QList<EspeakVoice*>* voices = new QList<EspeakVoice*>();
    QRegularExpression re(LANGUAGE_REGEX);
    for (QString line : lines)
    {
        QRegularExpressionMatch m = re.match(line);
        if (m.hasMatch())
        {
            QString language = m.captured("language");
            QString name = m.captured("name");
            voices->append(new EspeakVoice(language, name));
        }
    }

    return voices;
}
