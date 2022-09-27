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
        dialog_2.cpp \
        main.cpp \
        mynon_qthread.cpp \
        mythread.cpp \
        testc.cpp \
        tlv_dat.cpp \
        trainthread.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../../radar_awr1843.h \
    dialog.h \
    dialog_2.h \
    mynon_qthread.h \
    mythread.h \
    testc.h \
    tlv_dat.h \
    trainthread.h

FORMS += \
    dialog.ui \
    dialog_2.ui
