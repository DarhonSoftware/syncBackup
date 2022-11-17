import QtQuick
import QtQuick.Controls
import com.darhon 1.0

Dialog {
    id: id_dialog
    width: id_labelRef.width*50
    height: id_labelRef.height*30
    anchors.centerIn: parent
    title: qsTr("About")
    modal: true
    standardButtons: Dialog.Ok

    About {id: id_about}
    Label { id: id_labelRef; text: "W"; visible: false }

    header: Rectangle {
        id: id_header
        height: id_title.height*1.5
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

        Column {
            id: id_main
            anchors.centerIn: parent
            width: parent.width-id_labelRef.height*2
            spacing: id_labelRef.height

            //ICON
            Image {
                id: id_iconAbout
                width: id_labelRef.height*4
                height: id_labelRef.height*4
                anchors.horizontalCenter: parent.horizontalCenter
                source: id_about.iconAbout
            }

            //Application name
            Label {
                id: id_appName
                anchors.horizontalCenter: parent.horizontalCenter
                text: id_about.appName
                font.bold: true
            }

            //Short sentence
            Label {
                id: id_caption
                anchors.horizontalCenter: parent.horizontalCenter
                text: id_about.caption
            }

            //Long sentence
            Label {
                id: id_description
                width: parent.width
                horizontalAlignment: Text.AlignJustify
                text: id_about.description
                wrapMode: Text.WordWrap
            }

            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 5

                Image {
                    id: id_iconDarhon
                    width: id_labelRef.height*2.5
                    height: id_labelRef.height*2.5
                    anchors.verticalCenter: parent.verticalCenter
                    source: id_about.iconDarhon
                }

                Column {
                    anchors.verticalCenter: parent.verticalCenter

                    Label {
                        id: id_copyright
                        text: id_about.copyright
                        font.pointSize: id_labelRef.font.pointSize*0.9
                    }
                    Label {
                        id: id_support
                        text: id_about.support
                        font.pointSize: id_labelRef.font.pointSize*0.9
                    }
                    Label {
                        id: id_privacy
                        text: id_about.privacy
                        font.pointSize: id_labelRef.font.pointSize*0.9
                        onLinkActivated: Qt.openUrlExternally(link)
                    }
                }
            }
        }
    }
}
