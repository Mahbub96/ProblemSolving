// Global variables 
var canvas = document.getElementById("myCanvas");
var c = canvas.getContext("2d");
const height = 400;
const width = 600;
var x1, y1;
var midX, midY;


// Create one dimensional array


// var a = 200 /* lets a = b = c = 200 */

class Point {
    constructor(x, y) {
        this.x = x;
        this.y = y
    }

}




// // Rendering part 
// function display(x, y, w, h) {
//     let Y = height - y - h;
//     c.fillRect(x, Y, w, h);
// }




function area(x1, y1, x2, y2, x3, y3) {
    return Math.abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

/* A function to check whether point P(x, y) lies inside the triangle formed
by A(x1, y1), B(x2, y2) and C(x3, y3) */

function isInside(x1, y1, x2, y2, x3, y3, x, y) {
    /* Calculate area of triangle ABC */
    let A = area(x1, y1, x2, y2, x3, y3);

    /* Calculate area of triangle PBC */
    let A1 = area(x, y, x2, y2, x3, y3);

    /* Calculate area of triangle PAC */
    let A2 = area(x1, y1, x, y, x3, y3);

    /* Calculate area of triangle PAB */
    let A3 = area(x1, y1, x2, y2, x, y);

    /* Check if sum of A1, A2 and A3 is same as A */
    return (A == (A1 + A2 + A3));
}

/* 3 points of this triangle */
A = new Point(0, 0);
B = new Point(300, 400);
C = new Point(600, 0);

/* to see triangle */
c.fillRect(0, 0, 5, 5);
c.fillRect(295, 395, 5, 5);
c.fillRect(595, 0, 5, 5);


function calculate(P) {
    midX = Math.round((x1 + P.x) / 2);
    midY = Math.round((y1 + P.y) / 2);
}


// starting point 
x1 = Math.round(Math.random() * 600);
y1 = Math.round(Math.random() * 400);

while (!isInside(0, 0, 300, 400, 600, 0, x1, y1)) {
    x1 = Math.round(Math.random() * 600);
    y1 = Math.round(Math.random() * 400);
}


setInterval(() => {
    let dise = Math.round(Math.random() * 6) + 1;

    if (dise < 3) calculate(A);
    else if (dise < 5) calculate(B);
    else if (dise < 7) calculate(C);

    c.fillRect(x1 - 1, y1 - 1, 1, 1); //print

    /* updating value */
    x1 = midX;
    y1 = midY;

}, 10);


