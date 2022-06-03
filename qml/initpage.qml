import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Dialogs 1.3

Page {
    id: id_initpage

    header: ToolBar {
        id: id_tootBar
        RowLayout {
            ToolButton {
                id: id_buttonSettings
                Layout.preferredWidth: id_labelRef.width*8
                enabled: !backend.isRunning
                text: qsTr("Settings")
                icon.source: "qrc:/images/settings.png"
                onClicked: id_initpage.StackView.view.push("qrc:/qml/settings.qml",StackView.Immediate)
            }
            ToolSeparator {
                id: id_separator1
            }
            Rectangle {
                Layout.preferredHeight: id_buttonSettings.height-4
                Layout.preferredWidth: id_labelFile.width+id_labelRef.width*2
                Layout.alignment: Qt.AlignVCenter
                border.width: 1
                border.color: palette.buttonText
                color: palette.button
                Label {
                    id: id_labelFile
                    anchors.centerIn: parent
                    font.family: "mono"
                    text: backend.displayConfFileName(backend.confFileName)
                }
            }
            ToolButton {
                id: id_buttonLoad
                Layout.preferredWidth: id_labelRef.width*8
                enabled: !backend.isRunning
                text: qsTr("Load")
                icon.source: "qrc:/images/load.png"
                onClicked: id_fileOpenDialog.open()
            }
            ToolButton {
                id: id_buttonSaveAs
                Layout.preferredWidth: id_labelRef.width*8
                enabled: !backend.isRunning
                text: qsTr("Save As")
                icon.source: "qrc:/images/save.png"
                onClicked: id_fileSaveDialog.open()
            }
            ToolButton {
                id: id_buttonReset
                Layout.preferredWidth: id_labelRef.width*8
                enabled: !backend.isRunning
                text: qsTr("Reset")
                icon.source: "qrc:/images/reset.png"
                onClicked: {
                    backend.resetConfiguration()
                    backend.confFileName=""
                }
            }
        }
    }

    Label {id: id_labelRef; text: "W"; visible: false;}

    ColumnLayout {
        width: parent.width-10
        height: parent.height-30
        anchors.centerIn: parent
        spacing: 20

        Frame {
            id: id_frame1
            Layout.fillWidth: true

            ColumnLayout {
                width: parent.width
                spacing: 2

                RowLayout {
                    Button {
                        id: id_buttonBrowseFrom
                        Layout.preferredWidth: id_labelRef.width*8
                        enabled: !backend.isRunning
                        text: qsTr("Local");
                        icon.source: "qrc:/images/folder.png"
                        onClicked: id_folderFromDialog.open()
                    }
                    Button {
                        id: id_buttonSshFrom
                        Layout.preferredWidth: id_labelRef.width*8
                        enabled: !backend.isRunning
                        text: qsTr("Remote");
                        icon.source: "qrc:/images/remote.png"
                        onClicked: id_sshFromDialog.open()
                    }
                    Rectangle {
                        id: id_rectFrom
                        border.color: palette.buttonText
                        border.width: 1
                        color: palette.button
                        Layout.preferredWidth: id_labelRef.width*10
                        Layout.preferredHeight: id_buttonBrowseFrom.height
                        Label {
                            id: id_labelFrom
                            anchors.centerIn: parent
                            text: qsTr("SOURCE")
                        }
                    }
                    TextField {
                        id: id_fieldFrom
                        readOnly: true
                        Layout.fillWidth: true
                        text: backend.from
                    }
                    TextField {
                        id: id_fieldFromPort
                        visible: backend.fromPort!=="-1"
                        readOnly: true
                        Layout.preferredWidth: id_labelRef.width*7
                        horizontalAlignment: TextInput.AlignHCenter
                        text: backend.fromPort
                    }
                }

                RowLayout {
                    Button {
                        id: id_buttonBrowseTo
                        Layout.preferredWidth: id_labelRef.width*8
                        enabled: !backend.isRunning
                        text: qsTr("Local");
                        icon.source: "qrc:/images/folder.png"
                        onClicked: id_folderToDialog.open()
                    }
                    Button {
                        id: id_buttonSshTo
                        Layout.preferredWidth: id_labelRef.width*8
                        enabled: !backend.isRunning
                        text: qsTr("Remote");
                        icon.source: "qrc:/images/remote.png"
                        onClicked: id_sshToDialog.open()
                    }
                    Rectangle {
                        id: id_rectTo
                        border.color: palette.buttonText
                        border.width: 1
                        color: palette.button
                        Layout.preferredWidth: id_labelRef.width*10
                        Layout.preferredHeight: id_buttonBrowseTo.height
                        Label {
                            id: id_labelTo
                            anchors.centerIn: parent
                            text: qsTr("DESTINATION")
                        }
                    }
                    TextField {
                        id: id_fieldTo
                        readOnly: true
                        Layout.fillWidth: true
                        text: backend.to
                    }
                    TextField {
                        id: id_fieldToPort
                        visible: backend.toPort!=="-1"
                        readOnly: true
                        Layout.preferredWidth: id_labelRef.width*7
                        horizontalAlignment: TextInput.AlignHCenter
                        text: backend.toPort
                    }
                }

            }
        }

        Frame {
            id: id_frame2
            Layout.fillWidth: true

            ColumnLayout {
                width: parent.width
                spacing: 2

                RowLayout {
                    Button {
                        id: id_buttonRun
                        enabled: !backend.isRunning
                        Layout.preferredWidth: id_labelRef.width*8
                        text: qsTr("Run");
                        icon.source: "qrc:/images/run.png"
                        onClicked:  {
                            id_textOutput.clear()
                            backend.run(id_checkRunDry.checked)
                        }
                    }
                    CheckBox {
                        id: id_checkRunDry
                        enabled: !backend.isRunning
                        text: qsTr("Run the process as a trial without making changes")
                    }
                    Item {
                        Layout.fillWidth: true
                    }
                    BusyIndicator {
                        running: backend.isRunning
                    }
                    Button {
                        id: id_buttonCancel
                        enabled: backend.isRunning
                        Layout.preferredWidth: id_labelRef.width*8
                        text: qsTr("Cancel");
                        icon.source: "qrc:/images/cancel.png"
                        onClicked: backend.cancel()
                    }
                }
            }
        }

        GroupBox {
            id: id_frame3
            Layout.fillWidth: true
            visible: backend.del || backend.deleteExcluded || !backend.update
            label: Label {
                font.bold: true
                text: " "+qsTr("WARNINGS in current configuration")
            }

            ColumnLayout {
                anchors.fill: parent
                spacing: 4

                Label {
                    visible: backend.del
                    text: "- "+qsTr("Delete files in the destination, if they are no longer in the source")
                }
                Label {
                    visible: backend.deleteExcluded
                    text: "- "+qsTr("Delete files in the destination, if they are marked as excluded in the source")
                }
                Label {
                    visible: !backend.update
                    text: "- "+qsTr("Replace files in the destination, even if modified time is newer than the source")
                }
            }
        }

        Rectangle {
            id: id_frame4
            Layout.fillHeight: true
            Layout.fillWidth: true
            border.color: palette.dark
            border.width: 1
            color: palette.base

            ScrollView {
                anchors.fill: parent
                clip: true
                TextArea {
                    id: id_textOutput
                    readOnly: true
                }
            }
        }
    }

    FileDialog {
        id: id_fileOpenDialog
        title: qsTr("Open configuration file")
        defaultSuffix: "syb"
        folder: backend.confFileName=="" ? shortcuts.documents : "file://"+backend.translatePathfromQML(backend.confFileName,false)
        nameFilters: "syncBackup (*.syb)"
        selectExisting: true
        selectFolder: false
        onAccepted: {
            if (backend.loadConfiguration(backend.translatePathfromQML(fileUrl))) {
                backend.confFileName=backend.translatePathfromQML(fileUrl)
            } else {
                id_messageDialog.text=qsTr("The configuration file couldn't be opened, it may not be in the correct format")
                id_messageDialog.open()
                backend.confFileName=""
            }
        }
    }

    FileDialog {
        id: id_fileSaveDialog
        title: qsTr("Save configuration file")
        defaultSuffix: "syb"
        folder: backend.confFileName=="" ? shortcuts.documents : "file://"+backend.translatePathfromQML(backend.confFileName,false)
        nameFilters: "syncBackup (*.syb)"
        selectExisting: false
        selectFolder: false
        onAccepted: {
            if (backend.saveConfiguration(backend.translatePathfromQML(fileUrl))) {
                backend.confFileName=backend.translatePathfromQML(fileUrl)
            } else {
                id_messageDialog.text=qsTr("The configuration file couldn't be saved")
                id_messageDialog.open()
                backend.confFileName=""
            }
        }
    }

    FileDialog {
        id: id_folderFromDialog
        title: qsTr("Select folder for SOURCE")
        folder: (backend.from=="" || backend.fromPort!="-1") ? shortcuts.home : "file://"+backend.from
        selectExisting: true
        selectFolder: true
        onAccepted: {
            backend.from=backend.translatePathfromQML(fileUrl)
            backend.fromPort="-1"
        }
    }

    FileDialog {
        id: id_folderToDialog
        title: qsTr("Select folder for DESTINATION")
        folder: (backend.to=="" || backend.toPort!="-1") ? shortcuts.home : "file://"+backend.to
        selectExisting: true
        selectFolder: true
        onAccepted: {
            backend.to=backend.translatePathfromQML(fileUrl)
            backend.toPort="-1"
        }
    }

    SSHDialog {
        id: id_sshFromDialog
        p_textAddress: backend.fromPort=="-1" ? "" : backend.from
        p_textPort: backend.fromPort=="-1" ? "" : backend.fromPort
        onAccepted: {
            backend.from=p_textAddress
            backend.fromPort=p_textPort
            if (backend.fromPort=="") backend.fromPort="22"
        }
    }

    SSHDialog {
        id: id_sshToDialog
        p_textAddress: backend.toPort=="-1" ? "" : backend.to
        p_textPort: backend.toPort=="-1" ? "" : backend.toPort
        onAccepted: {
            backend.to=p_textAddress
            backend.toPort=p_textPort
            if (backend.toPort=="") backend.toPort="22"
        }
    }

    MessageDialog {
        id: id_messageDialog
        title: qsTr("Information")
        standardButtons: StandardButton.Ok
        icon: StandardIcon.Information
    }

    Connections {
        target: backend
        function onProcessOutput(sOutput) {
            id_textOutput.append(sOutput)
        }
    }
}
