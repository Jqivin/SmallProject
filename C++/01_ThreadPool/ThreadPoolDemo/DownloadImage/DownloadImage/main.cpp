#include "DownloadImage.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DownloadImage window;
    window.show();
    return app.exec();
}
