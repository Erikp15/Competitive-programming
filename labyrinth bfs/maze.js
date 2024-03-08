let template = document.getElementById('app');


//let animations = document.getElementById('animations');

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

var canvas;
if(0){
    canvas = document.createElementNS('http://www.w3.org/2000/svg', 'svg');
    canvas.setAttribute('width', width*size);
    canvas.setAttribute('height', height*size);
} else {
    canvas = document.getElementsByTagName('svg')[0]; //Get svg element
}

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

//template.appendChild(canvas);







var queue = [];
queue.push(findstart());

bfs();

function bfs(){
    while(queue.length>0){
        var pos = queue.shift();
        tryPos({row:pos.row+1, col:pos.col}, maze, queue);
        tryPos({row:pos.row-1, col:pos.col}, maze, queue);
        tryPos({row:pos.row, col:pos.col+1}, maze, queue);
        tryPos({row:pos.row, col:pos.col-1}, maze, queue);
    }
}

function findstart(){
    for(var i=0;i<maze.length;i++){
        for(var j=0;j<maze[0].length;j++){
            if(maze[i][j]=='0'){
                return {row:maze.length,col:maze[0].length,steps:0};
            }
        }
    }
}

function tryPos(position, maze, queue){
    if(position.row>=maze.length || position.row<0 || position.col>=maze[0].length || position.col<0){
        console.log(position.steps);
        return;
    }
    if(maze[position.row][position.col]===' '){
        queue.pop(position);
        maze[position.row][position.col]=position.steps;
    }
    return;
}
