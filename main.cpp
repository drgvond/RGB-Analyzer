#include "qtquick2controlsapplicationviewer.h"
#include <QtQml>

int main(int argc, char *argv[])
{
    Application app(argc, argv);

    QtQuick2ControlsApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/RGB-Analyzer/main.qml"));
    viewer.show();

    return app.exec();
}
