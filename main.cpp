#include "mainwindow.h"
#include <QApplication>
#include<cstdio>
#include<cstring>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    //w.setFixedSize(522, 415);
    w.show();
    a.exec();
    return 0;
}
