#include "espeakrunnerfactory.h"

#include <QString>

static const QString UNIX_ESPEAK_PATH = "/usr/bin/espeak";

EspeakRunnerFactory::EspeakRunnerFactory() {}

EspeakRunner* EspeakRunnerFactory::get()
{
    return new EspeakRunner(UNIX_ESPEAK_PATH);
}
