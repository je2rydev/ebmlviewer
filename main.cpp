#include "mainwindow.h"
#include <QFile>
#include <QApplication>

void readEXMLFile(){
    QFile file("");
    if(!file.open(QIODevice::ReadWrite)){
        qCritical() << "Could not open file!";
        qCritical() << file.errorString();
        return;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.loadEbmlParser();
    w.show();
    return a.exec();
}
