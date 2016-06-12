#-------------------------------------------------
#
# Project created by QtCreator 2016-05-22T13:21:18
#
#-------------------------------------------------

QT       += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ISense
TEMPLATE = app


SOURCES += main.cpp\
        isense.cpp \
    sensorstabledialog.cpp \
    sensorstablemodel.cpp \
    connectioncontroller.cpp \
    sensor.cpp

HEADERS  += isense.h \
    sensorstabledialog.h \
    sensorstablemodel.h \
    connectioncontroller.h \
    sensor.h \
    commons.h

FORMS    += isense.ui \
    sensorstabledialog.ui

RESOURCES += \
    icons.qrc

DISTFILES += \
    Server/pthreadVC2.lib \
    Server/pthreadVC2.dll
