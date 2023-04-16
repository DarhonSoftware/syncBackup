import QtQuick
import QtQuick.Controls

Dialog {
    id: id_dialog
    width: id_labelRef.font.pixelSize * 60
    height: id_labelRef.font.pixelSize * 35
    title: qsTr("Guidelines to exclude or include files and directories")
    anchors.centerIn: parent
    modal: true
    standardButtons: Dialog.Ok

    Label {
        id: id_labelRef
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

    contentItem: Rectangle {
        anchors.top: header.bottom
        anchors.bottom: footer.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 2
        border.color: palette.dark
        border.width: 1
        color: palette.base

        ScrollView {
            anchors.fill: parent
            contentHeight: id_textHelp.height

            TextArea {
                id: id_textHelp
                width: parent.width
                wrapMode: TextEdit.WordWrap
                textFormat: TextEdit.RichText
                readOnly: true
                text: backend.excIncHelp
            }
        }
    }
}
