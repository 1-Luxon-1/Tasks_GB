import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import ru.gb.MygraphMetricClass 1.0
import QtCharts 2.15
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Graphs")

    GraphMetricClass
    {
        id:_graphClass
    }

    ComboBox
    {
        id:_listGraphs
        anchors.horizontalCenter: parent.horizontalCenter
        model:["y = x", "y = sin(x)", "y = |x - 2.5|", "y = x^2", "y = log2(x)"]
        onActivated:
        {
            if(_listGraphs.displayText === "y = x")
            {
                _lineGraph.clear()
                _graphClass.changeGraphType(_graphClass.yx)
                for(var i = 0;i<50;i++)
                {
                    _lineGraph.append(_graphClass.getX(i), _graphClass.getY(i))
                }
                parent.update()
            }
            else if(_listGraphs.displayText === "y = sin(x)")
            {
                _lineGraph.clear()
                _graphClass.changeGraphType(_graphClass.ySin)
                for(i = 0;i<50;i++)
                {
                    _lineGraph.append(_graphClass.getX(i), _graphClass.getY(i))
                }
                parent.update()
            }
            else if(_listGraphs.displayText === "y = |x - 2.5|")
            {
                _lineGraph.clear()
                _graphClass.changeGraphType(_graphClass.yx25)
                for(i = 0;i<50;i++)
                {
                    _lineGraph.append(_graphClass.getX(i), _graphClass.getY(i))
                }
                parent.update()
            }
            else if(_listGraphs.displayText === "y = x^2")
            {
                _lineGraph.clear()
                _graphClass.changeGraphType(_graphClass.yxpow2)
                for(i = 0;i<50;i++)
                {
                    _lineGraph.append(_graphClass.getX(i), _graphClass.getY(i))
                }
                parent.update()
            }
            else if(_listGraphs.displayText === "y = log2(x)")
            {
                _lineGraph.clear()
                _graphClass.changeGraphType(_graphClass.ylog2x)
                for(i = 0;i<50;i++)
                {
                    _lineGraph.append(_graphClass.getX(i), _graphClass.getY(i))
                }
                parent.update();
            }
        }
    }

    Item
    {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: _listGraphs.bottom
        ChartView
        {
            title: "Line"
            anchors.fill: parent
            antialiasing: true
            LineSeries
            {
                id: _lineGraph
                name: "LineSeries"
            }
        }
    }

}
