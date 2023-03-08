import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle
    {
        id: _rect
        anchors.centerIn: parent
        width: 200
        height: 150
        border.color: "black"
        border.width: 2
        color: "red"
        RotationAnimation
        {
            id: _animRotate
            target: _rect
            from: 0
            to: 360
            duration: 2000
        }
        MouseArea
        {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked:
            {
                if(mouse.button === Qt.LeftButton)
                {
                    _rect.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
                }
                else if(mouse.button === Qt.RightButton)
                {
                    _animRotate.running = true
                }
            }
            onDoubleClicked:
            {
                _rect.height = 200
                _rect.radius = 100
            }
        }
    }
}
