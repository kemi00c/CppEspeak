#include "optionssaver.h"
#include "options_filename.h"

OptionsSaver::OptionsSaver()
{
    this->fileSaver = new FileSaver(OPTIONS_FILENAME);
}

OptionsSaver::~OptionsSaver()
{
    delete this->fileSaver;
}

void OptionsSaver::save(Options options)
{
    QString data = QString(options.toJson().toJson());
    fileSaver->save(data);
}
