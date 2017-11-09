import QtQuick 2.7
import QtQml 2.2
import QtCanvas3D 1.1
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQml.Models 2.2

Rectangle {
    id : idTest
    layer.enabled: true
    layer.smooth: true
    layer.textureMirroring: ShaderEffectSource.NoMirroring
    width:128
    height: 64
    color: "red"

}
