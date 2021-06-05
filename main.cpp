#include "qtpvideoplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTPVideoPlayer w;
    w.show();

    return a.exec();
}
