import QtQuick 2.4
import com.bigcorp.imageanalysis 1.0

Rectangle {
    id: histView
    property RgbHistogram histogram

    width: 100
    height: 62
    color: "black"

    Row {
        Repeater {
            model: histogram.histogramData
             Item {
                 width: histView.width / histogram.binCount
                 height: histView.height
                 opacity: 0.6
                 Rectangle {
                     width: parent.width
                     height: redCount / histogram.maxValue * histView.height
                     y: parent.height - height
                     color: Qt.lighter("red")
                 }
                 Rectangle {
                     width: histView.width / histogram.binCount
                     height: greenCount / histogram.maxValue * histView.height
                     y: parent.height - height
                     color: Qt.lighter("green")
                 }
                 Rectangle {
                     width: histView.width / histogram.binCount
                     height: blueCount / histogram.maxValue * histView.height
                     y: parent.height - height
                     color: Qt.lighter("blue")
                 }
             }
        }
    }
}
