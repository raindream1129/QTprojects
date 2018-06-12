#-------------------------------------------------
#
# Project created by QtCreator 2018-04-27T09:06:24
#
#-------------------------------------------------

QT       += core gui
QT += axcontainer
QT      += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bar2excel
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    DBHelper.cpp \
    UdaoImp.cpp \
    dbstr_inf.cpp \
    StrIdao.cpp

HEADERS  += mainwindow.h \
    DBHelper.h \
    UdaoImp.h \
    dbstr_inf.h \
    StrIdao.h \
    common.h

FORMS    += mainwindow.ui
