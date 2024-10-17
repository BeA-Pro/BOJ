const dy=[-1,1,0,0];
const dx=[0,0,-1,1];
let n,m;

function checkMove(dir, move, y, x,park){
    let cnt = 0;
    let ny = y, nx = x;
    while(cnt < move){
        ny += dy[dir];
        nx += dx[dir];
        if(!(0 <= ny && ny < n && 0 <= nx && nx < m && park[ny][nx]!="X")) return false;
        cnt+=1;
    }
    return true;
}

function solution(park, routes) {
    var answer = [];
    n = park.length
    m = park[0].length;
    let y = 0,x = 0;
    
    for(let i =0;i<n;i++){
        for(let j=0;j<m;j++){
            if(park[i][j] == "S"){
                y = i;
                x = j;
            }
        }
    }

    for(const a of routes){
        const route = a.split(" ");
        let dir = 0;
        let move = parseInt(route[1]);
        if(route[0]=="N") dir = 0;
        else if(route[0]=="S") dir = 1;
        else if(route[0]=="W") dir = 2;
        else if(route[0]=="E") dir = 3;
        
        if(!checkMove(dir,move,y,x,park)) continue;
        y += dy[dir] * move;
        x += dx[dir] * move;
        
    }
    return [y,x];
}