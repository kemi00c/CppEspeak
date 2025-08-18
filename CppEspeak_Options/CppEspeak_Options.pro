QT -= gui

TEMPLATE = lib
DEFINES += CPPESPEAK_OPTIONS_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cppespeak_options.cpp \
    options.cpp \
    optionsloader.cpp \
    optionssaver.cpp

HEADERS += \
    CppEspeak_Options_global.h \
    cppespeak_options.h \
    options.h \
    options_filename.h \
    optionsloader.h \
    optionssaver.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../CppEspeak_Espeak/build/Desktop-Debug/release/ -lCppEspeak_Espeak
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../CppEspeak_Espeak/build/Desktop-Debug/debug/ -lCppEspeak_Espeak
else:unix: LIBS += -L$$PWD/../CppEspeak_Espeak/build/Desktop-Debug/ -lCppEspeak_Espeak

INCLUDEPATH += $$PWD/../CppEspeak_Espeak
DEPENDPATH += $$PWD/../CppEspeak_Espeak

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../CppEspeak_Cli/build/Desktop-Debug/release/ -lCppEspeak_Cli
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../CppEspeak_Cli/build/Desktop-Debug/debug/ -lCppEspeak_Cli
else:unix: LIBS += -L$$PWD/../CppEspeak_Cli/build/Desktop-Debug/ -lCppEspeak_Cli

INCLUDEPATH += $$PWD/../CppEspeak_Cli
DEPENDPATH += $$PWD/../CppEspeak_Cli

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../CppEspeak_FileSystem/build/Desktop-Debug/release/ -lCppEspeak_FileSystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../CppEspeak_FileSystem/build/Desktop-Debug/debug/ -lCppEspeak_FileSystem
else:unix: LIBS += -L$$PWD/../CppEspeak_FileSystem/build/Desktop-Debug/ -lCppEspeak_FileSystem

INCLUDEPATH += $$PWD/../CppEspeak_FileSystem
DEPENDPATH += $$PWD/../CppEspeak_FileSystem
