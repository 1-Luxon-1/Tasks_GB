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
