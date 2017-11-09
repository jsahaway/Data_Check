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

    onInitialWidthChanged: {
        GLCode.setResizeWindow(mainView.width, mainView.height);
    }
    Item{
        id: idTexture
        visible: false


    }

//    ListView {
//        //width :  100; height: 4000
//        visible: false
//        interactive: false
//        model : myModel

//        delegate: ListView {
//            width :  100; height: 30000

//            visible: false
//            interactive: false
//            model : modelData.myList

//            Component.onCompleted: {

//            }

//            delegate: Text {
//                id: textureSource
//                layer.enabled: true
//                layer.smooth: true
//                layer.textureMirroring: ShaderEffectSource.NoMirroring
//                width: 64
//                height: 32
//                anchors.centerIn: parent
//                visible: false
//                text: modelData
//                font.pixelSize: 14
//                color: "black"
//                transform: [
//                    Scale {
//                        origin.y: textureSource.height / 2
//                        origin.x: textureSource.width / 2
//                        yScale: 0.5 * mainView.height / mainView.initialHeight
//                        xScale: 0.5 * mainView.height / mainView.initialHeight
//                    }
//                ]
//                Component.onCompleted: {
//                    GLCode.setTextureSource(textureSource);
//                }
//            }
//        }
//    }



//        Text {
//            id: textureSource
//            layer.enabled: true
//            layer.smooth: true
//            layer.textureMirroring: ShaderEffectSource.NoMirroring
//            width: 64
//            height: 32
//            anchors.centerIn: parent
//            visible: false
//            text: currentTexttoText


//            font.pixelSize: 14
//            color: "black"
//            transform: [
//                Scale {
//                    origin.y: textureSource.height / 2
//                    origin.x: textureSource.width / 2
//                    yScale: 0.5 * mainView.height / mainView.initialHeight
//                    xScale: 0.5 * mainView.height / mainView.initialHeight
//                }
//            ]
//            Component.onCompleted: {
//                GLCode.setTextureSource(textureSource);
//            }
//            //        onTextChanged: {
//            //            for (var i = 0; i < myModel[0].myList.length; ++i){
//            //                currentTexttoText = myModelToText.push(i);
//            //                GLCode.setTextureSource(textureSource);
//            //            }
//            //        }
//        }


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
