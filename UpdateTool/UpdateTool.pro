#-------------------------------------------------
#
# Project created by QtCreator 2018-01-25T13:01:08
#
#-------------------------------------------------

QT       += core gui serialport
QT      += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UpdateTool
TEMPLATE = app
QT += core


SOURCES += main.cpp\
        widget.cpp \
    common.cpp \
    DBHelper.cpp \
    UdaoImp.cpp \
    dbbnbxx.cpp \
    SoftWdao.cpp \
    dbsjixx.cpp

HEADERS  += widget.h \
    common.h \
    DBHelper.h \
    UdaoImp.h \
    dbbnbxx.h \
    SoftWdao.h \
    cjt188_fio.h \
    cjt188_general.h \
    dbsjixx.h

FORMS    += widget.ui
RC_FILE = proj.rc
