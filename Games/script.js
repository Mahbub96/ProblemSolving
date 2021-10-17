
// Global variables 
var canvas = document.getElementById("mycanvas");
var c = canvas.getContext("2d");
const height = 450;
const width = 40;

// Rendering part 
function display(x,y,w,h){
    var X = width - x;
    var Y = height - y - h;
    c.fillRect(X,Y,w,h);
}


setInterval(() => {
    
    display(0,0,30,40);
    
}, 200);

