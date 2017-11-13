import QtQuick 2.7
import QtQml 2.2
import QtCanvas3D 1.1
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQml.Models 2.2

// Great for small amount of data
// ListView don't show data that out of its view...
ListView {
    visible: false
    interactive: false
    model : myModel

    delegate: ListView {

        width :  100; height: 30000
        visible: false
        interactive: false
        model : modelData.myList

        delegate: Text {
            id: textureSource
            layer.enabled: true
            layer.smooth: true
            layer.textureMirroring: ShaderEffectSource.NoMirroring
            width: 64
            height: 32
            anchors.centerIn: parent
            visible: false
            text: modelData
            font.pixelSize: 14
            color: "black"
            transform: [
                Scale {
                    origin.y: textureSource.height / 2
                    origin.x: textureSource.width / 2
                    yScale: 0.5 * mainView.height / mainView.initialHeight
                    xScale: 0.5 * mainView.height / mainView.initialHeight
                }
            ]

            Component.onCompleted: {
                GLCode.setTextureSource(textureSource);
            }
        }
    }
}


// Simple way with Text to pass qml type to threejs as texture
//Text {
//    id: textureSource
//    layer.enabled: true
//    layer.smooth: true
//    layer.textureMirroring: ShaderEffectSource.NoMirroring
//    width: 64
//    height: 32
//    anchors.centerIn: parent
//    visible: false
//    text: currentTexttoText

//    font.pixelSize: 14
//    color: "black"
//    transform: [
//        Scale {
//            origin.y: textureSource.height / 2
//            origin.x: textureSource.width / 2
//            yScale: 0.5 * mainView.height / mainView.initialHeight
//            xScale: 0.5 * mainView.height / mainView.initialHeight
//        }
//    ]
//    Component.onCompleted: {
//        GLCode.setTextureSource(textureSource);
//    }
//}
