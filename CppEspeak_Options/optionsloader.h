#ifndef OPTIONSLOADER_H
#define OPTIONSLOADER_H

#include "fileloader.h"
#include "options.h"

class OptionsLoader
{
private:
    FileLoader* fileLoader;
public:
    OptionsLoader();
    ~OptionsLoader();

    Options* load();
};

#endif // OPTIONSLOADER_H
