let template = document.getElementById('app');
let animations = document.getElementById('animations');

const maze = [
    ['*','*','*',' ','*','*','*'],
    ['*','s','*',' ',' ','*','*'],
    ['*',' ','*','*',' ',' ',' '],
    ['*',' ',' ','*',' ','*','*'],
    ['*',' ',' ',' ',' ','*','*'],
    ['*','*','*',' ','*','*','*'],
    ['*',' ',' ',' ','*','*','*'],
    ['*',' ','*','*','*','*','*'], 
    ['*',' ','*','*','*','*','*'], 
];
let size = 50;
// y height
// x width
let height = maze.length;
let width = maze[0].length;


let canvas = document.createElementNS('http://www.w3.org/2000/svg', 'svg');
canvas.setAttribute('width', width*size);
canvas.setAttribute('height', height*size);

let appendElement = (canvas, node, maze) => {
    let colors = {
        '*':'red',
        ' ':'gray',
        's':'lime'
    };

    let blockRef = document.createElementNS('http://www.w3.org/2000/svg', 'Rect');
        blockRef.setAttribute('height', size);
        blockRef.setAttribute('width', size);
        blockRef.setAttribute('x', node.x*size);
        blockRef.setAttribute('y', node.y*size);
        blockRef.setAttribute('fill', colors[maze[node.y][node.x]]);
    canvas.appendChild(blockRef);

}

maze.map((row, y, arr) => {
    row.map((col, x ) => {
        appendElement(canvas, {x, y}, maze);
    });
});

if(0){
    let path = document.createElementNS('http://www.w3.org/2000/svg', 'path');
    path.setAttribute('d', 'M 0,0 L50 50 L50 0 L0 0 Z');
    path.setAttribute('stroke', 'red');
    path.setAttribute('fill', 'none');
    canvas.appendChild(path);
}

template.appendChild(canvas);