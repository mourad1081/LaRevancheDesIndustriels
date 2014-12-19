#include "application.h"
#include <QApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Application w;
    w.show();
    cout <<"";
    return a.exec();
}
