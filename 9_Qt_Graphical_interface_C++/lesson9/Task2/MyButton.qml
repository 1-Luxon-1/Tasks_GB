import QtQuick 2.15
import Tasks 1.0
BorderImage
{
    signal clicked

    id: _button
    source: "qrc:///img/buttonIsNotPressed.png"
    width: _txt.width+15
    height: _txt.height+10
    border.bottom: 10
    border.left: 10
    border.right: 10
    border.top: 10

    Text {
        id: _txt
        text: qsTr("Добавить задачу")
        color:"white"
        anchors.centerIn: parent
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: parent.clicked()
        onPressed:
        {

            _button.source = "qrc:///img/buttonIsPressed.png"
        }
        onReleased:
        {
            _button.source = "qrc:///img/buttonIsNotPressed.png"
        }

    }

}
