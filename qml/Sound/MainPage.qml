import QtQuick 1.1
import com.nokia.symbian 1.1

Page {
    id: mainPage
    Button{
        text : "test"
        anchors.centerIn: parent
        onClicked: {
            bgm.play()
        }
    }



}
