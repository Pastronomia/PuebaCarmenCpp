#include "map.h"

void Map::showMap() {
    int argc = 0;
    char *argv[] = {nullptr};
    QApplication app(argc, argv);

    QMainWindow window;
    QWebEngineView *view = new QWebEngineView(&window);

    // URL del mapa de Colonia, Uruguay
    view->setUrl(QUrl("https://www.welcomeuruguay.com/colonia/map.html"));

    window.setCentralWidget(view);
    window.resize(800, 600);
    window.show();

    app.exec();
}
