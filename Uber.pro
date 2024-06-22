#-------------------------------------------------
#
# Project created by QtCreator 2024-05-30T13:07:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Uber
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    mainview.cpp \
    loginview.cpp \
    rideview.cpp \
    billview.cpp \
    logincontroller.cpp \
    maincontroller.cpp \
    ridecontroller.cpp \
    billcontroller.cpp \
    usermodel.cpp \
    ordermodel.cpp \
    registerview.cpp \
    logoview.cpp \
    evaluateview.cpp \
    orderhistoryview.cpp \
    orderhistorycontroller.cpp

HEADERS += \
    mainview.h \
    loginview.h \
    rideview.h \
    billview.h \
    logincontroller.h \
    maincontroller.h \
    ridecontroller.h \
    billcontroller.h \
    usermodel.h \
    ordermodel.h \
    registerview.h \
    logoview.h \
    evaluateview.h \
    1_template.h \
    orderhistoryview.h \
    orderhistorycontroller.h

FORMS += \
    loginview.ui \
    rideview.ui \
    billview.ui \
    mainview.ui \
    registerview.ui \
    logoview.ui \
    evaluateview.ui \
    orderhistoryview.ui

RESOURCES += \
    logo.qrc

