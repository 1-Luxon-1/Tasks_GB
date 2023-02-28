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
                Layout.topMargin: 10
                Layout.leftMargin: 30
            }

            TextField
            {
                id: _tf2
                placeholderText: "Введите дату"
                Layout.topMargin: 10
            }

            TextField
            {
                id: _tf3
                placeholderText: "Введите прогресс"
                Layout.topMargin: 10
            }
        }
        RowLayout
        {
            Label
            {
                text: "Количество задач:"
                Layout.leftMargin: 30
            }

            TextEdit
            {
                id: _textNumTasks
                text: _tasks.getNumTasks()
            }
        }

        RowLayout
        {

            MyButton
            {
                Layout.leftMargin: 100
                onClicked:
                {
                    _tasks.addTasks(_tf1.getText(0,3), _tf2.getText(0,10), _tf3.getText(0,1))
                    _textNumTasks.text(_tasks.getNumTasks())
                }

            }
        }
    }
}
