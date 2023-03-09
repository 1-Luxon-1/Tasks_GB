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
        antialiasing: true
        border.color: "black"
        border.width: 2
        color: "red"

        states:
        [
            State
            {
                name: "rec"
                PropertyChanges
                {
                    target: _rect
                    height: 150
                    width: 200
                }
            },

            State
            {
                name: "circle"
                PropertyChanges {
                    target: _rect
                    height: 200
                    radius: 150
                }
            },
            State {
            name: "rotation"
            when: mouseArea.pressed
            PropertyChanges { target: _rect}
            }
        ]

        transitions:
        [
            Transition
            {
                to: "rec"
                PropertyAnimation{duration:200}

            },

            Transition {
                to: "circle"
                PropertyAnimation{duration:2000}
            },

            Transition {
                to: "rotation"
                RotationAnimation
                {
                    target: _rect
                    from: 0
                    to: 360
                    duration: 2000
                }
            }
        ]

        MouseArea
        {
            id: mouseArea
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
                    _rect.state = "rotation"
                }
            }
            onDoubleClicked:
            {
                if(mouse.button === Qt.LeftButton)
                if (_rect.state === "circle")
                {
                    _rect.state = "rec"
                }
                else
                {
                    _rect.state = "circle"
                }
            }
        }
    }
}
