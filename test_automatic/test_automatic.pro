#-------------------------------------------------
#
# Project created by QtCreator 2018-05-29T11:52:06
#
#-------------------------------------------------

QT       += core gui
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_automatic
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    common.cpp \
    writeLog.cpp \
    dialog.cpp \
    totalizer.cpp

HEADERS  += mainwindow.h \
    cjt188_fio.h \
    cjt188_general.h \
    common.h \
    writeLog.h \
    dialog.h \
    totalizer.h

FORMS    += mainwindow.ui \
    dialog.ui \
    totalizer.ui
