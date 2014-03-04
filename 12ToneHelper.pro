#-------------------------------------------------
#
# Project created by QtCreator 2014-03-03T19:30:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 12ToneHelper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tonenamewidget.cpp

HEADERS  += mainwindow.h \
    tonenamewidget.h

FORMS    += mainwindow.ui \
    tonenamewidget.ui

OTHER_FILES +=

RESOURCES += \
    images.qrc

QMAKE_CXXFLAGS += -std=c++11
