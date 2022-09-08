QT      -= gui
QT      += serialport
QT      += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../../radar_awr1843.cpp \
        dialog.cpp \
        main.cpp \
        mythread.cpp \
        testc.cpp \
        trainthread.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../../radar_awr1843.h \
    dialog.h \
    mythread.h \
    testc.h \
    trainthread.h

FORMS += \
    dialog.ui
