let xRot = 0;
let yRot = 0;
let zRot = 0;

let locZ = 150;

let red = 127;
let green = 127;
let blue = 127;

let incVal = .03;

function setup() {
  createCanvas(400, 400, WEBGL);
  background(30);
  noStroke();
  noCursor();
}

function draw() {
  background(0);
	spheres();
  keys();
}

function keys() {

  if (keyIsPressed == true) {
    // "a"
    if (keyCode == 97) {
      xRot += incVal;
    }
    // "s"
    if (keyCode == 115) {
      yRot += incVal
    }
    // "d"
    if (keyCode == 100) {
      zRot += incVal;
    }
    // "q"
    if (keyCode == 113) {
      locZ -= 1;
    }
    // "e"
    if (keyCode == 101) {
      locZ += 1;
    }
    //rotation in radians (theta), take sine, +1, * 127 
    red = nf((sin(xRot) + 1) * 127, 3, 0);
    green = nf((sin(yRot) + 1) * 127, 3, 0);
    blue = nf((sin(zRot) + 1) * 127, 3, 0);
    // console.log("r " + red + ", g " + green + ", b " + blue);
  }
}

function spheres() {

	let locX = mouseX - width / 2;
  let locY = mouseY - height / 2;

  pointLight(red, green, blue, locX - 10, locY, locZ);
  pointLight(red, green, blue, locX + 10, locY, locZ);

  push();
  translate(0, 0, -700);
  sphere(500);
  pop();

  push();
  translate(0, 0, -100);
  sphere(70);
  pop();

  push();
  translate(locX, locY, locZ);
  rotateX(xRot);
  rotateY(yRot);
  rotateZ(zRot);

  push();
  translate(-10, 0, 0);
  sphere(3);
  pop();

  push();
  translate(10, 0, 0);
  sphere(3);
  pop();

	stroke(red, green, blue);
	strokeWeight(5);
	line(-10, 0, 10, 0);
	noStroke();

  pop();
}
