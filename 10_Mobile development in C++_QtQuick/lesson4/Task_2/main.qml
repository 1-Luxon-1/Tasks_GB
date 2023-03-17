import QtQuick 2.15
import QtQuick.Window 2.15
import QtCharts 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item
    {
        anchors.fill: parent
        ChartView
        {
            title: "Диаграмма рассеяния"
            anchors.fill: parent
            antialiasing: true
            ScatterSeries
            {
                id: _scatter
                name: "Набор данных"
                XYPoint { x: 7; y: 13 }
                XYPoint { x: 31; y: 10 }
                XYPoint { x: 61; y: 9 }
                XYPoint { x: 99; y: 10 }
                XYPoint { x: 129; y: 12 }
                XYPoint { x: 178; y: 20 }
                XYPoint { x: 209; y: 26 }
            }

            // y = 0,0677x + 7,38
            LineSeries
            {
                id: _line
                name: "Апроксимированные данные"
                XYPoint{x: 1; y: 7.448}
                XYPoint{x: 2; y: 7.515}
                XYPoint{x: 5; y: 7.719}
                XYPoint{x: 17; y: 8.531}
                XYPoint{x: 34; y: 9.682}
                XYPoint{x: 50; y: 10.765}
                XYPoint{x: 83; y: 12.99}
                XYPoint{x: 112; y: 14.962}
                XYPoint{x: 205; y: 21.259}
            }
        }
    }
}
