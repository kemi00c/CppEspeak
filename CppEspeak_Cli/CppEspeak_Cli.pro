QT -= gui

TEMPLATE = lib
DEFINES += CPPESPEAK_CLI_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cppespeak_cli.cpp \
    espeakrunner.cpp \
    espeakrunnerfactory.cpp

HEADERS += \
    CppEspeak_Cli_global.h \
    cppespeak_cli.h \
    espeakrunner.h \
    espeakrunnerfactory.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
