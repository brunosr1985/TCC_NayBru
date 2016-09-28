#-------------------------------------------------
#
# Project created by QtCreator 2016-05-02T20:56:02
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JanelasTCC
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    cadastropessoa.cpp \
    cadastrochamado.cpp \
    matrizraci.cpp \
    cadastrodispositivo.cpp \
    selecionadisp.cpp

HEADERS  += mainwindow.h \
    cadastropessoa.h \
    cadastrochamado.h \
    matrizraci.h \
    cadastrodispositivo.h \
    selecionadisp.h

FORMS    += mainwindow.ui \
    cadastropessoa.ui \
    cadastrochamado.ui \
    matrizraci.ui \
    cadastrodispositivo.ui \
    selecionadisp.ui

DISTFILES +=
