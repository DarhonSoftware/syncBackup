import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3
import com.darhon 1.0

ApplicationWindow {
    id: id_appWindow
    menuBar:  MenuBar {
        Menu {
            title: qsTr("&Menu")
            Action {
                text: qsTr("&Command")
                icon.name: "utilities-terminal"
                onTriggered: {
                    id_commandlineDialog.p_textCommand=backend.exportCommandLine()
                    id_commandlineDialog.open()
                }
            }
            Action {
                text: qsTr("&Help")
                icon.name: "help-contents"
                onTriggered: id_helpDialog.open()
            }
            Action {
                text: qsTr("&About")
                icon.name: "help-about"
                onTriggered: id_aboutDialog.open()
            }
            MenuSeparator { }
            Action {
                text: qsTr("&Quit")
                icon.name: "application-exit"
                onTriggered: id_appWindow.close()
            }
        }
    }

    MainWindow {id: id_mainWindow}

    StackView {
        id: id_stack
        anchors.fill: parent
        initialItem: "qrc:/qml/initpage.qml"
    }

    AboutDialog {
        id: id_aboutDialog
    }

    MessageDialog {
        id: id_messageDialog
        title: qsTr("Alert")
        icon: StandardIcon.Warning
        standardButtons: StandardButton.Yes|StandardButton.No
        text: qsTr("The process is running, do you still want to close the application?")
        onYes: Qt.quit()
    }

    CommandlineDialog {
        id: id_commandlineDialog
    }

    HelpDialog {
        id: id_helpDialog
    }

    Component.onCompleted: {
        backend.init()
        x=id_mainWindow.x
        y=id_mainWindow.y
        width=id_mainWindow.width
        height=id_mainWindow.height
        visible=true
    }

    Component.onDestruction: {
        id_mainWindow.x=x
        id_mainWindow.y=y
        id_mainWindow.width=width
        id_mainWindow.height=height
        backend.end()
    }

    onClosing: {
        if (backend.isRunning) {
            id_messageDialog.open()
            close.accepted=false
        }
    }
}
