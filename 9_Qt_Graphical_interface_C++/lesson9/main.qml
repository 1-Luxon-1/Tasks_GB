import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import Tasks 1.0
Window
{
    width: 640
    height: 480
    visible: true
    title: qsTr("Organizer")

    Tasks
    {
        id: _tasks
    }


}
