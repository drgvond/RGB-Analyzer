import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    title: qsTr("Histogram")
    width: 800
    height: 480

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")

            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    SplitView {
        anchors.fill: parent

        Image {
            id: imageView
            Layout.minimumWidth: 200
            fillMode: Image.PreserveAspectFit
        }

        Item {
            TabView {
                anchors.fill: parent
                anchors.margins: 12

                Tab {
                    id: tableTab
                    title: "Table"
                }

                Tab {
                    title: "Histogram"
                }
            }
        }
    }
}
