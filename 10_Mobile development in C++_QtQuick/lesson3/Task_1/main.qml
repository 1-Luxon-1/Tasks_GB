import QtQuick 2.15
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

        states:
            [
                State
                {
                    name: "beginning"
                    PropertyChanges
                    {
                        target: _layout
                        opacity: 1
                    }
                },
                State
                {
                    name: "registration"
                    PropertyChanges
                    {
                        target: _layout;
                        opacity: 0
                    }
                }
            ]
        transitions:
            [
                Transition
                {
                    to: "registration"
                    OpacityAnimator{duration: 1000}
                },
                Transition
                {
                    to: "beginning"
                    OpacityAnimator{duration: 500}
                }
            ]
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
           if(_layout.state === "registration")
           {
               _layout.state = "beginning"
               _infoWindow.state = "novisible"
               _buttonRegistration.text = "Зарегистрироваться"
           }
           else
           {
               _layout.state = "registration"
               _infoWindow.state = "visible"
               _buttonRegistration.text = "Отмена"
           }

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

    Rectangle
    {
        visible: true
        id: _infoWindow
        anchors.centerIn: parent
        height: 100
        width: 400
        color: "lightgreen"
        border.color: "yellow"
        border.width: 2
        Text
        {
            text: "Вы успешно зарегистрированы"
            anchors.centerIn: parent
            font.bold: true
            font.pixelSize: 20
        }
        state: "novisible"
        states:
            [
                State
                {
                    name: "novisible"
                    PropertyChanges
                    {
                        target: _infoWindow
                        visible: false
                    }
                },
                State
                {
                   name: "visible"
                   PropertyChanges {
                       target: _infoWindow
                       visible: true
                   }
                }

            ]
    }

}
