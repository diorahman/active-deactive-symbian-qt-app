import QtQuick 1.1
import com.nokia.symbian 1.1
import test.app 1.0

PageStackWindow {
    id: window
    initialPage: MainPage {tools: toolBarLayout}
    showStatusBar: true
    showToolBar: true

    BackgroundMusic{
        id: bgm
    }

    ToolBarLayout {
        id: toolBarLayout
        ToolButton {
            flat: true
            iconSource: "toolbar-back"
            onClicked: window.pageStack.depth <= 1 ? Qt.quit() : window.pageStack.pop()
        }
    }

    Connections{
        target: AppEvents
        onActivated : { bgm.play()}
        onDeactivated : { bgm.stop()}

    }
}
