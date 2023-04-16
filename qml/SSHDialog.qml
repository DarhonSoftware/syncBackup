import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Dialog {
    id: id_dialog
    property alias p_textPort: id_fieldPort.text
    property alias p_textAddress: id_fieldAddress.text

    width: id_labelRef.width * 70
    height: header.height + footer.height + id_main.height * 1.5
    title: qsTr("Address to remote server")
    anchors.centerIn: parent
    modal: true
    standardButtons: Dialog.Save | Dialog.Cancel

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

            RowLayout {
                Label {
                    id: id_labelPort
                    Layout.preferredWidth: id_labelAddress.width
                    text: qsTr("Port")
                }
                TextField {
                    id: id_fieldPort
                    Layout.fillWidth: true
                    inputMethodHints: Qt.ImhDigitsOnly
                    validator: IntValidator {
                        bottom: 0
                    }
                    placeholderText: "22"
                }
            }

            RowLayout {
                Label {
                    id: id_labelAddress
                    text: qsTr("Address")
                }
                TextField {
                    id: id_fieldAddress
                    Layout.fillWidth: true
                    placeholderText: qsTr("USER@HOST:PATH (username@200.150.150.11:backup_folder)")
                }
            }
        }
    }
}
