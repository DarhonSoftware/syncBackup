import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: id_settings

    header: ToolBar {
        id: id_tootBar
        RowLayout {
            ToolButton {
                id: id_buttonBack
                Layout.preferredWidth: id_labelRef.width*8
                text: qsTr("Back")
                icon.source: "qrc:/qt/qml/darhon/images/back.png"
                onClicked: id_settings.StackView.view.pop(StackView.Immediate)
            }
        }
    }

    Label {id: id_labelRef; text: "W"; visible: false;}

    ColumnLayout {
        width: parent.width-10
        height: parent.height-30
        anchors.centerIn: parent
        spacing: 20

        RowLayout {
            id: id_row1
            spacing: 2

            GroupBox {
                id: id_group1
                Layout.preferredWidth: parent.width/2
                Layout.preferredHeight: id_group2.height
                clip: true
                label: Label {
                    text: " "+qsTr("Configure files in destination")
                    font.bold: true
                }
                ColumnLayout {
                    CheckBox {
                        id: id_checkGroup
                        text: qsTr("Set the <u>group</u> of the destination file to be the same as the source")
                        checked: backend.group
                        onToggled: backend.group=checked
                    }
                    CheckBox {
                        id: id_checkOwner
                        text: qsTr("Set the <u>owner</u> of the destination file to be the same as the source")
                        checked: backend.owner
                        onToggled: backend.owner=checked
                    }
                    CheckBox {
                        id: id_checkPerms
                        text: qsTr("Set the <u>permission</u> of the destination file to be the same as the source")
                        checked: backend.perms
                        onToggled: backend.perms=checked
                    }
                    CheckBox {
                        id: id_checkLinks
                        text: qsTr("When a <u>symlink</u> is encountered, recreates the symlink in the destination")
                        checked: backend.links
                        onToggled: backend.links=checked
                    }
                }
            }

            GroupBox {
                id: id_group2
                Layout.fillWidth: true
                clip: true
                label: Label {
                    text: " "+qsTr("Configure actions in destination")
                    font.bold: true
                }
                ColumnLayout {
                    CheckBox {
                        id: id_checkDel
                        text: qsTr("Delete files in the destination, if they are no longer in the source")
                        checked: backend.del
                        onToggled: backend.del=checked
                    }
                    CheckBox {
                        id: id_checkDeleteExcluded
                        text: qsTr("Delete files in the destination, if they are marked as excluded in the source")
                        checked: backend.deleteExcluded
                        onToggled: backend.deleteExcluded=checked
                    }
                    CheckBox {
                        id: id_checkIgnoreNonExisting
                        text: qsTr("Only update existing files in the destination. Do not transfer new files")
                        checked: backend.ignoreNonExisting
                        onToggled: backend.ignoreNonExisting=checked
                    }
                    CheckBox {
                        id: id_checkIgnoreExisting
                        text: qsTr("Do not replace files in the destination, if they already exist")
                        checked: backend.ignoreExisting
                        onToggled: backend.ignoreExisting=checked
                    }
                    CheckBox {
                        id: id_checkUpdate
                        text: qsTr("Do not replace files in the destination, when modified time is newer than the source")
                        checked: backend.update
                        onToggled: backend.update=checked
                    }
                }
            }
        }

        GroupBox {
            id: id_group3
            Layout.fillWidth: true
            clip: true
            label: Label {
                text: " "+qsTr("Configure actions in source")
                font.bold: true
            }
            ColumnLayout {
                CheckBox {
                    id: id_checkRecursive
                    text: qsTr("Copy directories recursively")
                    checked: backend.recursive
                    onToggled: backend.recursive=checked
                }
                RowLayout {
                    CheckBox {
                        id: id_checkMaxSize
                        text: qsTr("Avoid transferring files larger than")
                        checked: backend.maxSize
                        onToggled: backend.maxSize=checked
                    }
                    TextField {
                        id: id_fieldMaxSizeAmount
                        enabled: id_checkMaxSize.checked
                        inputMethodHints: Qt.ImhDigitsOnly
                        validator: IntValidator{bottom: 0}
                        text: backend.maxSizeValue
                        onEditingFinished: backend.maxSizeValue=text
                    }
                    ComboBox {
                        id: id_comboUnit
                        enabled: id_checkMaxSize.checked
                        model: ["Bytes","KBytes","MBytes","GBytes"]
                        currentIndex: backend.unit
                        onActivated: backend.unit=currentIndex
                    }
                }
            }
        }

        GroupBox {
            id: id_group4
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            label: Label {
                text: qsTr("List of files and directories to be excluded and included")
                font.bold: true
            }

            ColumnLayout {
                id: id_columnExcInc
                anchors.fill: parent
                spacing: 5

                RowLayout {
                    id: id_rowExcInc1
                    spacing: 5

                    TextField {
                        id: id_fieldtPath
                        Layout.fillWidth: true
                        placeholderText: qsTr("Compose PATH to insert in Excluded or Included")
                    }
                    Button {
                        text: qsTr("Help")
                        Layout.preferredWidth: id_labelRef.width*8
                        icon.source: "qrc:/qt/qml/darhon/images/help.png"
                        onClicked: id_ExcInclDialog.open()
                    }
                }

                RowLayout {
                    id: id_rowExcInc2
                    spacing: 5

                    ColumnLayout {
                        id: id_columnExc

                        RowLayout {
                            Label {
                                text: qsTr("EXCLUDED")
                                font.bold: true
                            }
                            Button {
                                id: id_buttonExcInsert
                                Layout.preferredWidth: id_labelRef.width*8
                                text: qsTr("Insert")
                                icon.source: "qrc:/qt/qml/darhon/images/insert.png"
                                onClicked: {
                                    if (id_fieldtPath.text!="") backend.addExclude(id_fieldtPath.text)
                                    id_fieldtPath.text=""
                                }
                            }
                            Button {
                                id: id_buttonExcDelete
                                Layout.preferredWidth: id_labelRef.width*8
                                text: qsTr("Delete")
                                icon.source: "qrc:/qt/qml/darhon/images/delete.png"
                                onClicked: backend.removeExclude(id_listExc.currentIndex)
                            }
                        }

                        Rectangle {
                            id: id_rectExc
                            Layout.preferredWidth: id_group1.width
                            Layout.fillHeight: true
                            border.width: 1
                            border.color: palette.dark
                            color: palette.base
                            ListView {
                                id: id_listExc
                                anchors.fill: parent
                                anchors.margins: 2
                                model: modelExc
                                snapMode: ListView.SnapToItem
                                clip: true
                                activeFocusOnTab: true
                                delegate: id_delegateExcInc

                                ScrollIndicator.vertical: ScrollIndicator {}
                            }
                        }
                    }

                    ColumnLayout {
                        id: id_columnInc

                        RowLayout {
                            Label {
                                text: qsTr("INCLUDED")
                                font.bold: true
                            }
                            Button {
                                id: id_buttonIncInsert
                                Layout.preferredWidth: id_labelRef.width*8
                                text: qsTr("Insert")
                                icon.source: "qrc:/qt/qml/darhon/images/insert.png"
                                onClicked: {
                                    if (id_fieldtPath.text!="") backend.addInclude(id_fieldtPath.text)
                                    id_fieldtPath.text=""
                                }
                            }
                            Button {
                                id: id_buttonIncDelete
                                Layout.preferredWidth: id_labelRef.width*8
                                text: qsTr("Delete")
                                icon.source: "qrc:/qt/qml/darhon/images/delete.png"
                                onClicked: backend.removeInclude(id_listInc.currentIndex)
                            }
                        }

                        Rectangle {
                            id: id_rectInc
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            border.width: 1
                            border.color: palette.dark
                            color: palette.base
                            ListView {
                                id: id_listInc
                                anchors.fill: parent
                                anchors.margins: 2
                                model: modelInc
                                snapMode: ListView.SnapToItem
                                clip: true
                                activeFocusOnTab: true
                                delegate: id_delegateExcInc

                                ScrollIndicator.vertical: ScrollIndicator {}
                            }
                        }
                    }
                }
            }
        }
    }

    Component {
        id: id_delegateExcInc

        ItemDelegate {
            id: id_delegateExcInc1
            property bool p_editMode: false
            width: ListView.view.width
            text: role_c0

            contentItem: Text {
                id: id_textExcInc
                z: 1
                visible: !p_editMode
                text: id_delegateExcInc1.text
                color: id_highlightRect.visible ? palette.highlightedText : palette.text
                verticalAlignment: Text.AlignVCenter
            }

            Rectangle {
                id: id_highlightRect
                anchors.fill: parent
                color: palette.highlight
                visible: id_delegateExcInc1.ListView.isCurrentItem
            }

            TextField {
                id: id_fieldEditExcInc
                anchors.fill: parent
                anchors.rightMargin: 5
                visible: p_editMode
                onEditingFinished: {
                    role_c0=text
                    p_editMode=false
                }
                onVisibleChanged: {
                    text=role_c0
                    if (visible) focus=true
                }
            }

            onPressed: ListView.view.currentIndex=index
            onDoubleClicked: p_editMode=true

            Keys.onPressed: {
                if (event.key===Qt.Key_F2) {
                    doubleClicked()
                    event.accepted=true
                }
            }

            Keys.onEscapePressed: p_editMode=false
            Keys.onUpPressed: if (ListView.view.currentIndex>0) ListView.view.currentIndex--
            Keys.onDownPressed: if (ListView.view.currentIndex<ListView.view.count-1) ListView.view.currentIndex++
        }
    }

    ExcIncHelpDialog {
        id: id_ExcInclDialog
    }
}
