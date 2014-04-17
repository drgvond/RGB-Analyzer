import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import com.bigcorp.imageanalysis 1.0

ApplicationWindow {
    title: qsTr("Hello World")
    width: 800
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
        enabled: imageView.source != ""
        onTriggered: hist.compute()
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

    RgbHistogram {
        id: hist
        imageSource: imageView.source
        binCount: 20
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
                    title: "Table"
                    TableView {
                        anchors.fill: parent
                        anchors.margins: 12
                        model: hist.histogramData

                        TableViewColumn {
                            title: "#"
                            role: "binNumber"
                            width: 45
                        }
                        TableViewColumn {
                            title: "Red"
                            role: "redCount"
                            width: 65
                        }
                        TableViewColumn {
                            title: "Green"
                            role: "greenCount"
                            width: 65
                        }
                        TableViewColumn {
                            title: "Blue"
                            role: "blueCount"
                            width: 65
                        }
                    }
                }
            }
        }
    }
}
