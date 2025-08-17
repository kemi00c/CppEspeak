#ifndef ESPEAKRUNNERFACTORY_H
#define ESPEAKRUNNERFACTORY_H

#include "espeakrunner.h"

class EspeakRunnerFactory
{
public:
    EspeakRunnerFactory();

    static EspeakRunner* get();
};

#endif // ESPEAKRUNNERFACTORY_H
