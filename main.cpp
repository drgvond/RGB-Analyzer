#include "qtquick2controlsapplicationviewer.h"
#include "rgbhistogram.h"
#include <QtQml>

int main(int argc, char *argv[])
{
    Application app(argc, argv);

    QtQuick2ControlsApplicationViewer viewer;
    qmlRegisterType<RgbHistogram>("com.bigcorp.imageanalysis", 1, 0, "RgbHistogram");
    viewer.setMainQmlFile(QStringLiteral("qml/RGB-Analyzer/main.qml"));
    viewer.show();

    return app.exec();
}
