// Mouse (x, y, z);
// can move.xy to point to a table3D
// if point.table3D so move.z
//
// z = view of the scene :
// mouse.z = view.scene -> view.table -> view.property
// view.scene : move around all the scene in orbit
// view.table : enter point.mode
// view.property : point.mode + move.table


function MYMouse() {
    this.coordX = 0;
    this.coordY = 0;
    this.coordZ = 10;
    this.mapX = 0;
    this.mapY = 0;
    this.mapZ = 0;

    this.events = 0;


    this.setX = function(x){
        this.coordX = x;
        this.mapX = ((x/initialWidth) - 0.5) * 10;
    };

    this.setY = function(y){
        this.coordY = y;
        this.mapY = ((y/initialHeight) - 0.5) * -1;
    };

    this.setZ = function(z){
        this.coordZ += (z/10) * -1;
    };
}
