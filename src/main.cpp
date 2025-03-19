#include "backend.h"
QT += core gui
CONFIG += c++17

INCLUDEPATH += /path/to/qt/include
LIBS += -L/path/to/qt/lib

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    loadHotkeys();
    registerHotkeys();

    MainWindow window;
    window.show();

    return app.exec();
}
