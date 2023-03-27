import Felgo
import QtQuick 2.15
import QtQml 2.15
import QtQuick.Controls 2.15

App
{
     Navigation
    {
        NavigationItem
        {
            title: "Notes"
            icon: IconType.thlarge
            NavigationStack
            {
                Page
                {
                    id: page1
                    title: "Notes"

                    AppButton
                    {
                        id: _buttonNote1
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: parent.top
                        anchors.topMargin: 50
                        text: "Notebook 1"
                        onClicked:
                        {
                            page1.navigationStack.push(_notePad1)
                        }
                    }

                    AppButton
                    {
                        id: _buttonNote2
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: _buttonNote1.bottom
                        anchors.topMargin: 50
                        text: "Notebook 2"
                        onClicked:
                        {
                            page1.navigationStack.push(_notePad2)
                        }
                    }

                    AppButton
                    {
                        id: _buttonNote3
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: _buttonNote2.bottom
                        anchors.topMargin: 50
                        text: "Notebook 3"
                        onClicked:
                        {
                            page1.navigationStack.push(_notePad3)
                        }
                    }
                }
            }
        }

        NavigationItem
        {
            title: "Important"
            icon: IconType.thlarge
            NavigationStack
            {
                Page
                {
                    id: page2
                    title: "Important"
                    AppButton
                    {
                        id: _buttonNote11
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: parent.top
                        anchors.topMargin: 50
                        text: "Personal 1"
                        onClicked:
                        {
                            page2.navigationStack.push(_notePad1)
                        }
                    }

                    AppButton
                    {
                        id: _buttonNote22
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: _buttonNote1.bottom
                        anchors.topMargin: 50
                        text: "Personal 2"
                        onClicked:
                        {
                            page2.navigationStack.push(_notePad2)
                        }
                    }

                    AppButton
                    {
                        id: _buttonNote33
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: _buttonNote2.bottom
                        anchors.topMargin: 50
                        text: "Personal 3"
                        onClicked:
                        {
                            page2.navigationStack.push(_notePad3)
                        }
                    }
                }
            }
        }
      }


    Component
    {
        id: _notePad1
        Page
        {
            Rectangle
            {
                id:_rect
                anchors.horizontalCenter: parent.parent.horizontalCenter
                anchors.top: parent.parent.top
                anchors.topMargin: 50
                width: parent.parent.width
                height: parent.parent.height
                color: "lightyellow"
            }

            AppFlickable
            {
              id: flick
              anchors.fill: parent
              contentWidth: width
              contentHeight: appTextEdit.height

              AppTextEdit
              {
                  id: appTextEdit
                  width: parent.width
                  height: Math.max(appTextEdit.contentHeight, flick.height)
                  verticalAlignment: TextEdit.AlignTop
                  cursorInView: true
                  cursorInViewBottomPadding: dp(25)
                  cursorInViewTopPadding: dp(25)
                  flickable: flick
              }
            }
        }
    }


    Component
    {
        id: _notePad2
        Page
        {
            Rectangle
            {
                id:_rect
                anchors.horizontalCenter: parent.parent.horizontalCenter
                anchors.top: parent.parent.top
                anchors.topMargin: 50
                width: parent.parent.width
                height: parent.parent.height
                color: "lightblue"
            }

            AppFlickable
            {
              id: flick
              anchors.fill: parent
              contentWidth: width
              contentHeight: appTextEdit.height

              AppTextEdit
              {
                  id: appTextEdit
                  width: parent.width
                  height: Math.max(appTextEdit.contentHeight, flick.height)
                  verticalAlignment: TextEdit.AlignTop
                  cursorInView: true
                  cursorInViewBottomPadding: dp(25)
                  cursorInViewTopPadding: dp(25)
                  flickable: flick
              }
            }
        }
    }

    Component
    {
        id: _notePad3
        Page
        {
            Rectangle
            {
                id:_rect
                anchors.horizontalCenter: parent.parent.horizontalCenter
                anchors.top: parent.parent.top
                anchors.topMargin: 50
                width: parent.parent.width
                height: parent.parent.height
                color: "lightgrey"
            }

            AppFlickable
            {
              id: flick
              anchors.fill: parent
              contentWidth: width
              contentHeight: appTextEdit.height

              AppTextEdit
              {
                  id: appTextEdit
                  width: parent.width
                  height: Math.max(appTextEdit.contentHeight, flick.height)
                  verticalAlignment: TextEdit.AlignTop
                  cursorInView: true
                  cursorInViewBottomPadding: dp(25)
                  cursorInViewTopPadding: dp(25)
                  flickable: flick
              }
            }
        }
    }
}




/*import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Acquaintances")

    GridLayout
    {
        id: _layout
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 50
        rowSpacing: 15

        Label
        {
            id: _lblName
            Layout.row: 0
            Layout.column: 1
            text: "Имя: "
        }

        TextField
        {
            id: _name
            Layout.row: 0
            Layout.column: 2
            placeholderText: "Введите имя"
        }

        Label
        {
            id: _lblSecondname
            Layout.row: 1
            Layout.column: 1
            text: "Фамилия: "
        }

        TextField
        {
            id: _secondname
            Layout.row: 1
            Layout.column: 2
            placeholderText: "Введите фамилию"
        }

        Label
        {
            id: _lblGender
            Layout.row: 2
            Layout.column: 1
            text: "Пол: "
        }

        ComboBox
        {
            id: _gender
            Layout.row: 2
            Layout.column: 2
            Layout.leftMargin: 20
            model: ["М", "Ж"]
        }

        Label
        {
            id: _lblAge
            Layout.row: 3
            Layout.column: 1
            text: "Возраст: "
        }

        TextField
        {
            id: _age
            Layout.row: 3
            Layout.column: 2
            placeholderText: "Введите возраст"
        }

        Label
        {
            id: _lblEducation
            Layout.row: 4
            Layout.column: 1
            text: "Образование: "
        }

        ComboBox
        {
            id: _education
            width: 200
            Layout.row: 4
            Layout.column: 2
            Layout.columnSpan: 2
            Layout.leftMargin: 10
            model: ["Среднее общее", "Среднее профессиональное", "Высшее"]
        }

        Label
        {
            id: _lblHobby
            Layout.row: 5
            Layout.column: 1
            text: "Хобби: "
        }

        TextField
        {
            id: _hobby
            Layout.row: 5
            Layout.column: 2
            placeholderText: "Напишите свое хобби"
        }

        Label
        {
            id: _lblCity
            Layout.row: 6
            Layout.column: 1
            text: "Город: "
        }

        TextField
        {
            id: _city
            Layout.row: 6
            Layout.column: 2
            placeholderText: "Город проживания"
        }

        Label
        {
            id: _lblInfo
            Layout.row: 7
            Layout.column: 1
            text: "О себе: "
        }

        TextField
        {
            id: _info
            Layout.row: 7
            Layout.column: 2
            placeholderText: "Расскажите о себе"
        }

        Label
        {
            id: _lblSearchPartner
            Layout.row: 8
            Layout.column: 1
            text: "О партнёре"
            font.bold: true
        }

        Label
        {
            id: _lblAgePartner
            Layout.row: 9
            Layout.column: 0
            text: "Возраст от/до:"
        }

        Slider
        {
            id: _selectAge
            Layout.row: 9
            Layout.column: 1
            from: 12.0
            to: 80.0
            stepSize: 1.0
        }

        TextField
        {
            id: _showAgePartner
            Layout.row: 10
            Layout.column: 1
            width: 20
            text: _selectAge.value
        }

        Slider
        {
            id: _selectAge2
            Layout.row: 9
            Layout.column: 2
            from: 12.0
            to: 80.0
            stepSize: 1.0
        }

        TextField
        {
            id: _showAgePartner2
            Layout.row: 10
            Layout.column: 2
            width: 20
            text: _selectAge2.value
        }

        Label
        {
            id: _lblGenderPartner
            Layout.row: 9
            Layout.column: 3
            text: "Пол:"
        }

        ComboBox
        {
            id: _genderPartner
            Layout.row: 10
            Layout.column: 3
            model: ["М", "Ж"]
        }

        Label
        {
            id: _lblEducationPartner
            Layout.row: 9
            Layout.column: 4
            text: "Образование: "
        }

        ComboBox
        {
            id: _educationPartner
            width: 200
            Layout.row: 10
            Layout.column: 4
            Layout.columnSpan: 2
            model: ["Среднее общее", "Среднее профессиональное", "Высшее"]
        }
    }
    Button
    {
       id: _buttonRegistration
       text: "Зарегистрироваться"
       anchors.horizontalCenter: parent.horizontalCenter
       anchors.top: _layout.bottom
       anchors.topMargin: 20
       onClicked:
       {
           print("Имя: " + _name.text
                 + "\nФамилия: " + _secondname.text
                 + "\nПол: " + _gender.currentText
                 + "\nВозраст: " + _age.text
                 + "\nОбразование: " + _education.currentText
                 + "\nХобби: " + _hobby.text
                 + "\nГород: " + _city.text
                 + "\nО себе: " + _info.text
                 + "\nИщу партнёра\n"
                 + "Возраст от " + _selectAge.value
                 + " до " + _selectAge2.value + " лет"
                 + "\nпол: " + _genderPartner.currentText
                 + "\nобразование: " + _educationPartner.currentText)
       }
    }

}
*/
