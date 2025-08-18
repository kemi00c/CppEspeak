#ifndef OPTIONSSAVER_H
#define OPTIONSSAVER_H

#include "filesaver.h"
#include "options.h"

class OptionsSaver
{
private:
    FileSaver* fileSaver;
public:
    OptionsSaver();
    ~OptionsSaver();
    void save(Options options);
};

#endif // OPTIONSSAVER_H
