import QtQuick 2.4
import com.bigcorp.ImageAnalysis 1.0

Rectangle {
    id: histView
    property RgbHistogram histogram

    width: 100
    height: 62
    color: "white"
    border.color: "lightgrey"

    Row {
        Repeater {
            model: histogram.binCount
             Item {
                 width: histView.width / histogram.binCount
                 height: histView.height
                 opacity: 0.5
                 Rectangle {
                     width: parent.width
                     height: histogram.redCount(index) / histogram.maxValue * histView.height
                     y: parent.height - height
                     color: "red"
                 }
                 Rectangle {
                     width: histView.width / histogram.binCount
                     height: histogram.greenCount(index) / histogram.maxValue * histView.height
                     y: parent.height - height
                     color: "green"
                 }
                 Rectangle {
                     width: histView.width / histogram.binCount
                     height: histogram.blueCount(index) / histogram.maxValue * histView.height
                     y: parent.height - height
                     color: "blue"
                 }
             }
        }
    }
}
