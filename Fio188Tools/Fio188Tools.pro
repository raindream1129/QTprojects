#-------------------------------------------------
#
# Project created by QtCreator 2018-01-24T16:32:20
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fio188Tools
TEMPLATE = app
QT += serialport
CONFIG-=console
QT += widgets
SOURCES += main.cpp\
        widget.cpp \
    common.cpp \
    writeLog.cpp \
    readjldata.cpp \
    readhstdt.cpp \
    reportperiod.cpp \
    netconfig.cpp

HEADERS  += widget.h \
    cjt188_general.h \
    common.h \
    cjt188_fio.h \
    writeLog.h \
    readjldata.h \
    readhstdt.h \
    reportperiod.h \
    netconfig.h

FORMS    += widget.ui \
    readjldata.ui \
    readhstdt.ui \
    reportperiod.ui \
    netconfig.ui

RC_FILE = proj.rc

RESOURCES += \
    image.qrc

DISTFILES +=
