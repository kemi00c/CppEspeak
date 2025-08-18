QT -= gui

TEMPLATE = lib
DEFINES += CPPESPEAK_FILESYSTEM_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cppespeak_filesystem.cpp \
    fileloader.cpp \
    filesaver.cpp

HEADERS += \
    CppEspeak_FileSystem_global.h \
    cppespeak_filesystem.h \
    fileloader.h \
    filesaver.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
