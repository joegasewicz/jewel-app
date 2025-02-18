#include <QApplication>
#include <QMainWindow>

#include "canvas.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow window;

    Canvas *canvas = new Canvas();
    window.setCentralWidget(canvas);

    window.setWindowTitle("Jewel App");
    window.resize(800, 600);
    window.show();

    return app.exec();
}
