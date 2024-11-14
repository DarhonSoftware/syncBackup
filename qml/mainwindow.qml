import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import darhon

ApplicationWindow {
    id: id_appWindow
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&Menu")
            Action {
                text: qsTr("&Command")
                icon.name: "utilities-terminal"
                icon.source: "qrc:/darhon/images/command.png"
                onTriggered: {
                    id_commandlineDialog.p_textCommand = backend.exportCommandLine()
                    id_commandlineDialog.open()
                }
            }
            Action {
                text: qsTr("&Help")
                icon.name: "help-contents"
                icon.source: "qrc:/darhon/images/help.png"
                onTriggered: id_helpDialog.open()
            }
            Action {
                text: qsTr("&About")
                icon.name: "help-about"
                icon.source: "qrc:/darhon/images/about1.png"
                onTriggered: id_aboutDialog.open()
            }
            MenuSeparator {}
            Action {
                text: qsTr("&Quit")
                icon.name: "application-exit"
                icon.source: "qrc:/darhon/images/quit.png"
                onTriggered: id_appWindow.close()
            }
        }
    }

    CMainWindow {
        id: id_mainWindow
    }

    StackView {
        id: id_stack
        anchors.fill: parent
        initialItem: "qrc:/darhon/qml/initpage.qml"
    }

    AboutDialog {
        id: id_aboutDialog
    }

    MessageDialog {
        id: id_messageDialog
        title: qsTr("Alert")
        buttons: MessageDialog.Yes | MessageDialog.No
        text: qsTr("The process is running, do you still want to close the application?")
        onAccepted: Qt.quit()
    }

    CommandlineDialog {
        id: id_commandlineDialog
    }

    HelpDialog {
        id: id_helpDialog
    }

    Component.onCompleted: {
        backend.init()
        x = id_mainWindow.x
        y = id_mainWindow.y
        width = id_mainWindow.width
        height = id_mainWindow.height
    }

    Component.onDestruction: {
        id_mainWindow.x = x
        id_mainWindow.y = y
        id_mainWindow.width = width
        id_mainWindow.height = height
        backend.end()
    }

    onClosing: {
        if (backend.isRunning) {
            id_messageDialog.open()
            close.accepted = false
        }
    }
}
