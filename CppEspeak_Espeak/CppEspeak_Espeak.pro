QT -= gui

TEMPLATE = lib
DEFINES += CPPESPEAK_ESPEAK_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cppespeak_espeak.cpp \
    espeaker.cpp \
    espeaksaver.cpp \
    espeakvoice.cpp \
    espeakvoices.cpp

HEADERS += \
    CppEspeak_Espeak_global.h \
    cppespeak_espeak.h \
    espeaker.h \
    espeaksaver.h \
    espeakvoice.h \
    espeakvoices.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../CppEspeak_Cli/build/Desktop-Debug/release/ -lCppEspeak_Cli
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../CppEspeak_Cli/build/Desktop-Debug/debug/ -lCppEspeak_Cli
else:unix: LIBS += -L$$PWD/../CppEspeak_Cli/build/Desktop-Debug/ -lCppEspeak_Cli

INCLUDEPATH += $$PWD/../CppEspeak_Cli
DEPENDPATH += $$PWD/../CppEspeak_Cli

message("Include paths: $$INCLUDEPATH")
