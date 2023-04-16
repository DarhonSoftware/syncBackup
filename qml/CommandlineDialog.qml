import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Dialog {
    id: id_dialog
    property alias p_textCommand: id_fieldCommand.text

    width: id_labelRef.width * 70
    height: header.height + footer.height + id_main.height * 1.5
    title: qsTr("Command")
    anchors.centerIn: parent
    modal: true
    standardButtons: Dialog.Ok

    Label {
        id: id_labelRef
        text: "W"
        visible: false
    }

    header: Rectangle {
        id: id_header
        height: id_title.height * 1.5
        width: parent.width
        color: "#494949"
        Label {
            id: id_title
            anchors.centerIn: parent
            font.bold: true
            color: "#e5e5e5"
            text: id_dialog.title
        }
    }

    contentItem: Item {
        ColumnLayout {
            id: id_main
            width: parent.width - 10
            anchors.centerIn: parent
            spacing: 5

            Button {
                id: id_buttonCopy
                Layout.preferredWidth: id_labelRef.width * 8
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("Copy")
                icon.source: "qrc:/qt/qml/darhon/images/copy.png"
                onClicked: backend.copyToClipboard(id_fieldCommand.text)
            }

            TextField {
                id: id_fieldCommand
                Layout.fillWidth: true
            }
        }
    }
}
