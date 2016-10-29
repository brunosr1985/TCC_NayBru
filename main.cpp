#include "mainwindow.h"
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Login l;

    //Temporariamente removido para não carregar tela de login e agilizar debug
    /*if(l.exec() == QDialog::Accepted)
    {
    w.show();
    }*/
    w.show();
    return a.exec();
}
