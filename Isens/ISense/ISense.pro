#-------------------------------------------------
#
# Project created by QtCreator 2016-05-22T13:21:18
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ISense
TEMPLATE = app


SOURCES += main.cpp\
        isense.cpp \
    sensorstabledialog.cpp \
    sensorstablemodel.cpp \
    addsensordialog.cpp

HEADERS  += isense.h \
    sensorstabledialog.h \
    sensorstablemodel.h \
    addsensordialog.h

FORMS    += isense.ui \
    sensorstabledialog.ui \
    addsensordialog.ui

RESOURCES += \
    icons.qrc
