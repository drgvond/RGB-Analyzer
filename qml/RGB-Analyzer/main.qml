import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480

    FileDialog {
        id: fileDialog
        folder: "/Users/gabi/Work/DevDays-Asia-2014/Pictures"
        onAccepted: imageView.source = fileUrl
    }

    Action {
        id: fileOpenAction
        text: qsTr("Open")
        shortcut: "Ctrl+O"
        onTriggered: fileDialog.open()
        iconSource: "qrc:/document-open.png"
    }

    Action {
        id: analyzeAction
        text: qsTr("Analyze")
        iconSource: "qrc:/tubes.png"
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")

            MenuItem {
                action: fileOpenAction
            }

            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    toolBar: ToolBar {
        Row {
            anchors.fill: parent

            ToolButton {
                action: fileOpenAction
            }

            ToolButton {
                action: analyzeAction
            }
        }
    }

    Image {
        id: imageView
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }
}
