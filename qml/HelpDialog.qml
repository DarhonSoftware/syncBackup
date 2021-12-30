import QtQuick 2.7
import QtQuick.Controls 2.15

Dialog {
    id: id_dialog
    width: id_labelRef.width*50
    height: id_labelRef.height*25
    title: qsTr("Help")
    anchors.centerIn: parent
    modal: true
    standardButtons: Dialog.Ok

    Label {id: id_labelRef; text: "W"; visible: false;}

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

    contentItem:  Rectangle {
        anchors.top: header.bottom
        anchors.bottom: footer.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 2
        border.color: "grey"
        border.width: 1

        ScrollView {
            anchors.fill: parent
            contentHeight: id_textHelp.height

            TextArea {
                id: id_textHelp
                width: parent.width
                wrapMode: TextEdit.WordWrap
                textFormat: TextEdit.RichText
                readOnly: true
                text: backend.help
            }
        }
    }
}
