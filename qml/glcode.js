Qt.include("three.js")
Qt.include("MYControls.js")


var camera, scene, renderer;
var myGeometry, myGroup;
var qmlTextures = [];
var myMouse = new MYMouse();

var nbLine, nbCol;

var modelSize = myModel[0].myList.length;
var modelSizeMap = modelSize/10;
var modelSizeMapMiddle = modelSizeMap/2;



//
// Init -------------------------------------------------------------
//
function initializeGL(canvas) {

    // Scene, Camera, Ligth //

    //loadModel();

    scene = new THREE.Scene();
    camera = new THREE.PerspectiveCamera(45, canvas.width / canvas.height, 0.1, 1000);
    camera.position.set(0,0,0);



    // Object 3D //

    console.log("myModel: " + myModel[0].myList.length)

    myGroup = new THREE.Object3D();

    for (var i = 0; i < myModel[0].myList.length; ++i){


        //console.log("myModel: " + myModel[0].myList[i])


        var component = Qt.createComponent("MyTextureSource.qml");
        var componentParent = component.createObject(idTexture, { myText : myModel[0].myList[i] });

        // Texturing
        var textTexture = new THREE.QtQuickItemTexture( componentParent );
        var myMaterial =   new THREE.MeshBasicMaterial({ map: textTexture,
                                                           side : THREE.DoubleSide});
        // Add Geometry + Material
        var planeGeometry = new THREE.PlaneBufferGeometry(3, 1, 1, 1);
        myGeometry = new THREE.Mesh(planeGeometry, myMaterial );

        // Translate Mesh
        //        if(i%3 == 0){
        //            myGeometry.position.y = (i%486) * -0.6;
        //        } else {
        //            myGeometry.position.x = (i%3) * 3.2;
        //            myGeometry.position.y = (i%486) * -0.6;
        //        }

        //                    myGeometry.position.x = (i%3) * 3.2;
        //        if(i%3 == 0){
        //                    myGeometry.position.y = (i%485) * -0.5;
        //        }

        myGeometry.position.x = Math.random() * modelSizeMap - modelSizeMapMiddle;
        myGeometry.position.y = Math.random() * modelSizeMap - modelSizeMapMiddle;
        myGeometry.position.z = Math.random() * modelSizeMap - modelSizeMapMiddle;

        myGeometry.rotation.x = Math.random() * 2 * Math.PI;
        myGeometry.rotation.y = Math.random() * 2 * Math.PI;
        myGeometry.rotation.z = Math.random() * 2 * Math.PI;

        myGeometry.matrixAutoUpdate = false;
        myGeometry.updateMatrix();
        myGroup.add( myGeometry );
    }

    scene.add(myGroup);



    // Renderer //

    renderer = new THREE.Canvas3DRenderer({ canvas: canvas,
                                              antialias: true,
                                              devicePixelRatio: canvas.devicePixelRatio,
                                              alpha:true });
    renderer.setSize(canvas.width, canvas.height);
    renderer.setClearColor( 0x8797d8, 1 );
}




//
// Resize & Paint ---------------------------------------------------
//
function resizeGL(canvas) {
    camera.aspect = canvas.width / canvas.height;
    camera.updateProjectionMatrix();

    renderer.setPixelRatio(canvas.devicePixelRatio);
    renderer.setSize(canvas.width, canvas.height);
}


function paintGL(canvas) {
    //camera.rotation.y = radius * Math.sin( mouseCoordX * Math.PI/360) * Math.cos(mouseCoordX * Math.PI/360);
    camera.position.x = myMouse.coordZ * Math.sin( myMouse.mapX );
    camera.position.y = myMouse.coordZ * Math.sin( myMouse.mapY );
    camera.position.z = myMouse.coordZ * Math.cos( myMouse.mapX );
    camera.lookAt( scene.position );
    camera.updateMatrix();

    //console.log(myMouse.orbitX + " " + myMouse.orbitZ);
    renderer.render(scene, camera);
}




//
// Function ---------------------------------------------------------
//
function setTextureSource(tex){
    qmlTextures.push(tex);
}

function setResizeWindow(width, heigth){

}

//function loadModel(){
//    for (var i = 0; i < myModel[0].myList.length; ++i){
//        //console.log("index: " + myModel[0].myList[i]);
//        qmlTextures.push(i);
//    }
//}



