import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import Tasks 1.0
Window
{
    width: 500
    height: 300
    visible: true
    title: qsTr("Organizer")

    Tasks
    {
        id: _tasks
    }

    ColumnLayout
    {
        RowLayout
        {
            TextField
            {
                id: _tf1
                placeholderText: "Введите задачу"
                Layout.topMargin: 50
                Layout.leftMargin: 30
            }

            TextField
            {
                id: _tf2
                placeholderText: "Введите дату"
                Layout.topMargin: 50
            }

            TextField
            {
                id: _tf3
                placeholderText: "Введите прогресс"
                Layout.topMargin: 50
            }
        }
        RowLayout
        {

            MyButton
            {
                Layout.leftMargin: 150
                onClicked: _tasks.addTasks(_tf1.getText(), _tf2.getText(), _tf3.getText())
            }

        }
    }
}
