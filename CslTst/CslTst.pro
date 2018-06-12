QT += core
QT -= gui

CONFIG += c++11

QT       += core gui serialport
QT += xml
QT += widgets


TARGET = CslTst
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    common.cpp \
    rdcfg.cpp \
    rdxml.cpp

HEADERS += \
    common.h \
    fun.h \
    rdcfg.h \
    rdxml.h
