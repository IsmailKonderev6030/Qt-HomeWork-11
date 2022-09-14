import QtQuick 2.15
import QtQuick.Window 2.15

import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

Window {
    width: 430
    height: 140

    maximumWidth: 430   //
    maximumHeight: 140  // fix size
    minimumWidth: 430   //
    minimumHeight: 140  //

    visible: true
    title: qsTr("Organizer")

    Connections {
        target: trw
        function onSignalPrintTotalTasks(text) {text4.text = text;}
    }

    Text{
        id: text1
        text: qsTr("Task Name: ")
        x: 10
    }

    TextField {
        id: textField1
        width: 150
        placeholderText: qsTr("Enter name...")
        x: 100
        maximumLength: 50

    }

    Text{
        id: text2
        text: qsTr("Date: ")
        y: text1.y + 35
        x: 10
    }

    TextField {
        id: textField2
        width: 150
        placeholderText: qsTr("Enter date...")
        x: 100
        y: text2.y
        validator: RegularExpressionValidator { regularExpression: /^(0?[1-9]|[10-29]\d|30|31)[^\w\d\r\n:](0?[1-9]|1?[0-2])[^\w\d\r\n:](\d{4}|\d{2})/ }
        maximumLength: 10
    }

    Text{
        id: text3
        text: qsTr("Progress: ")
        y: text2.y + 35
        x: 10
    }

    TextField {
        id: textField3
        width: 150
        placeholderText: qsTr("Enter progress...")
        x: 100
        y: text3.y
        maximumLength: 2
        validator: RegularExpressionValidator { regularExpression: /^([0-9]|10)/ }

    }

    Text{
        id: text4
        anchors.left: textField1.right
    }

    Button{
        id: button1
        text: qsTr("Add Task")
        x: 10
        y: text3.y + 35
        onClicked: trw.addToTasks(
                       textField1.text,
                       textField2.text,
                       textField3.text
                       )
    }

    Button{
        id: button2
        text: qsTr("Show all tasks")
        y: text3.y + 35
        x: 100
        onClicked: trw.slotShowAllTasks()
    }

}
