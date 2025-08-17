QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
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
