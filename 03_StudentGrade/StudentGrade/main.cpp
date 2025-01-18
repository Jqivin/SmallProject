#include "StudentGrade.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentGrade w;
    w.show();
    return a.exec();
}
