let app = document.getElementById('app');
app.innerHTML="inner";
app.outerHTML="outer";

let svg = document.createElement('svg'); 
svg.setAttribute("width", "640");
svg.setAttribute("height", "640");
var svg2 = document.getElementsByTagName('svg')[0]; //Get svg element
var newElement = document.createElementNS("http://www.w3.org/2000/svg", 'path'); //Create a path in SVG's namespace
newElement.setAttribute("width","200"); //Set path's data
newElement.setAttribute("height","200"); //Set path's data
newElement.setAttribute("d","M 0 0 L 100 100 L 0 100"); //Set path's data
newElement.style.stroke = "#900090"; //Set stroke colour
newElement.style.strokeWidth = "5px"; //Set stroke width
//app.appendChild(svg);
svg2.appendChild(newElement);








let div2 = document.createElement('div');
div2.setAttribute('style', 'backround:red');
div2.innerHTML = 'div2';




let path = document.createElementNS('http://www.w3.org/2000/svg', 'path');
path.setAttribute('d', 'M 0,0 L50 50 L50 0 L0 0 Z');
path.setAttribute('stroke', 'red');
path.setAttribute('fill', 'none');

//svg.appendChild(path);

let circle = document.createElementNS('http://www.w3.org/2000/svg', 'circle');
circle.setAttribute('cx', 150);
circle.setAttribute('cy', 150);
circle.setAttribute('r', 40);
circle.setAttribute('stroke', 'black');
circle.setAttribute('stroke-width', '2');
circle.setAttribute('fill','red');


let smileGroup = document.createElementNS('http://www.w3.org/2000/svg', 'g');

let smileBase = document.createElementNS('http://www.w3.org/2000/svg', 'circle');
smileBase.setAttribute('cx', 50);
smileBase.setAttribute('cy', 50);
smileBase.setAttribute('r', 40);
smileBase.setAttribute('stroke', 'black');
smileBase.setAttribute('stroke-width', '2');
smileBase.setAttribute('fill','red');

let lefteye = document.createElementNS('http://www.w3.org/2000/svg', 'circle');
lefteye.setAttribute('cx', 40);
lefteye.setAttribute('cy', 60);
lefteye.setAttribute('r', 40);
lefteye.setAttribute('stroke', 'black');
lefteye.setAttribute('stroke-width', '2');
lefteye.setAttribute('fill','red');
svg.appendChild(lefteye);

let righteye = document.createElementNS('http://www.w3.org/2000/svg', 'circle');
righteye.setAttribute('cx', 60);
righteye.setAttribute('cy', 60);
righteye.setAttribute('r', 40);
righteye.setAttribute('stroke', 'black');
righteye.setAttribute('stroke-width', '2');
righteye.setAttribute('fill','red');

smileGroup.appendChild(smileBase);
smileGroup.appendChild(lefteye);
smileGroup.appendChild(righteye);

//user.appendChild(canvas);
//canvas.appendChild(path);

let animationMotion = document.createElementNS('http://www.w3.org/2000/svg', 'animateMotion');

