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
    selecionadisp.cpp \
    gerenciachamados.cpp \
    gerenciapessoas.cpp \
    gerenciadispositivo.cpp \
    novogrupo.cpp \
    tipodisp.cpp \
    pessoa.cpp \
    dispositivo.cpp \
    chamado.cpp \
    status.cpp \
    m_raci.cpp \
    tipod.cpp \
    grupop.cpp \
    login.cpp \
    conectabanco.cpp \
    cadastrousuario.cpp \
    cadastrostatus.cpp \
    cadastroprioridade.cpp

HEADERS  += mainwindow.h \
    cadastropessoa.h \
    cadastrochamado.h \
    matrizraci.h \
    cadastrodispositivo.h \
    selecionadisp.h \
    gerenciachamados.h \
    gerenciapessoas.h \
    gerenciadispositivo.h \
    novogrupo.h \
    tipodisp.h \
    pessoa.h \
    dispositivo.h \
    chamado.h \
    status.h \
    m_raci.h \
    tipod.h \
    grupop.h \
    login.h \
    conectabanco.h \
    cadastrousuario.h \
    cadastrostatus.h \
    cadastroprioridade.h

FORMS    += mainwindow.ui \
    cadastropessoa.ui \
    cadastrochamado.ui \
    matrizraci.ui \
    cadastrodispositivo.ui \
    selecionadisp.ui \
    gerenciachamados.ui \
    gerenciapessoas.ui \
    gerenciadispositivo.ui \
    novogrupo.ui \
    tipodisp.ui \
    login.ui \
    cadastrousuario.ui \
    cadastrostatus.ui \
    cadastroprioridade.ui

DISTFILES +=

STATECHARTS += \
    Modelo de classes.scxml
