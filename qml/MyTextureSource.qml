import QtQuick 2.7
import QtQml 2.2
import QtCanvas3D 1.1
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQml.Models 2.2

//import "glcode.js" as GLCode


    Text {
        property string myText :"default"

        id: textureSource
        layer.enabled: true
        layer.smooth: true
        layer.textureMirroring: ShaderEffectSource.NoMirroring
        width: 64
        height: 32
        anchors.centerIn: parent
        visible: true
        text: myText
        font.pixelSize: 9
        color: "black"
            transform: [
                Scale {
                    origin.y: textureSource.height / 2
                    origin.x: textureSource.width / 2
                    yScale: 0.5 * mainView.height / mainView.initialHeight
                    xScale: 0.5 * mainView.height / mainView.initialHeight
                }
            ]
        //    Component.onCompleted: {
        //        GLCode.setTextureSource(textureSource);
        //    }
    }

