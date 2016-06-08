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
    addsensordialog.cpp \
    connectioncontroller.cpp

HEADERS  += isense.h \
    sensorstabledialog.h \
    sensorstablemodel.h \
    addsensordialog.h \
    connectioncontroller.h

FORMS    += isense.ui \
    sensorstabledialog.ui \
    addsensordialog.ui

RESOURCES += \
    icons.qrc
