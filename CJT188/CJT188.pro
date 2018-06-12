QT += core
QT -= gui

QT       += core gui serialport xml
 QT += widgets
CONFIG += c++11

TARGET = CJT188
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    common.cpp \
    rdxml.cpp \
    widget.cpp \
    writeLog.cpp

HEADERS += \
    cjt188_fio.h \
    cjt188_general.h \
    common.h \
    rdxml.h \
    widget.h \
    writeLog.h
