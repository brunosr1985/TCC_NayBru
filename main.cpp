#include "mainwindow.h"
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login l;
    l.show();
    //Temporariamente removido para não carregar tela de login e agilizar debug
    /*if(l.exec() == QDialog::Accepted)
    {
    JanelaPrincipal w;
    w.show();
    }*/
    return a.exec();
}
