import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1
import com.bigcorp.imageanalysis 1.0

ApplicationWindow {
    title: qsTr("Histogram")
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
        RowLayout {
            ToolButton {
                action: fileOpenAction
                Layout.maximumWidth: width
            }

            Slider {
                id: binCount
                minimumValue: 0
                maximumValue: 8
                tickmarksEnabled: true
                updateValueWhileDragging: false
                stepSize: 1
                value: 6
            }
        }
    }

    RgbHistogram {
        id: hist
        imageSource: imageView.source
        binCount: Math.pow(2, binCount.value)
        onBinCountChanged: compute()
        onImageSourceChanged: compute()
        onHistogramUpdated: console.log("histogram computed", hist.binCount)
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
                    anchors.fill: parent
                    anchors.margins: 12
                    RgbHistogramView {
                        histogram: hist
                    }
                }
            }
        }
    }
}
