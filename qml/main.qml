import QtQuick 2.7
import QtQml 2.2
import QtCanvas3D 1.1
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQml.Models 2.2


import "qrc:/qml/glcode.js" as GLCode

Window {

    property int initialWidth: mainView.width
    property int initialHeight: mainView.height
    property Text textureSource
    property var myModelToText: []
    property string currentTexttoText: ""
    //property ListElement myModelView: myModel.modelData

    id: mainView
    title: qsTr("test_threejs")
    width: 700
    height: 350
    visible: true



    Item{
        id: idTexture
        visible: false
    }




    MouseArea {
        acceptedButtons: Qt.AllButtons
        hoverEnabled: true
        anchors.fill: parent
        onPositionChanged: {
            if (onPositionChanged){
                GLCode.myMouse.setX(mouse.x);
                GLCode.myMouse.setY(mouse.y);
            }
        }
        onWheel: {
            GLCode.myMouse.setZ(wheel.angleDelta.y);
        }

    }

    Canvas3D {
        id: canvas3d
        anchors.fill: parent
        focus: true

        onInitializeGL: {
            GLCode.initializeGL(canvas3d);
        }

        onPaintGL: {
            GLCode.paintGL(canvas3d);
        }

        onResizeGL: {
            GLCode.resizeGL(canvas3d);
        }
    }
}
