class Solution {
    static boolean[][] blueVisit;
    static boolean[][] redVisit;
    static int n,m;
    static int eRedY, eRedX, eBlueY, eBlueX;
    static int answer = Integer.MAX_VALUE;
    static int[] dy = {-1,1,0,0}, dx = {0,0,-1,1};
    
    static boolean checkMove(int y, int x, boolean[][] visit, int[][] maze){
        return 0 <= y && y < n && 0 <= x && x < m && maze[y][x] == 0 && !visit[y][x];
    }
    
    static void simulation(int redY, int redX, int blueY, int blueX, int cnt,int[][] maze){
        if(redY == eRedY && redX == eRedX && blueY == eBlueY && blueX == eBlueX){
            answer = Math.min(cnt,answer);
            return;
        }
        
        // 빨강 움직이고 파랑 움직임
        if(redY == eRedY && redX == eRedX){
            for(int i = 0; i < 4; i++){
                int nBlueY = blueY + dy[i], nBlueX = blueX + dx[i];
                if(!checkMove(nBlueY,nBlueX,blueVisit,maze)) continue;
                blueVisit[nBlueY][nBlueX] = true;
                maze[nBlueY][nBlueX] = 5;
                maze[blueY][blueX] = 0;
                simulation(redY, redX, nBlueY, nBlueX, cnt+1, maze);
                blueVisit[nBlueY][nBlueX] = false;
                maze[nBlueY][nBlueX] = 0;
                maze[blueY][blueX] = 5;
            }
        }else{
            for(int i = 0; i < 4;i++){
                int nRedY = redY + dy[i], nRedX = redX + dx[i];
                if(!checkMove(nRedY,nRedX,redVisit,maze)) continue;
                redVisit[nRedY][nRedX] = true;
                maze[nRedY][nRedX] = 5;
                maze[redY][redX] = 0;
                for(int j = 0; j < 4; j++){
                    int nBlueY = blueY + dy[j], nBlueX = blueX + dx[j];
                    if(!checkMove(nBlueY,nBlueX,blueVisit,maze)) continue;
                    blueVisit[nBlueY][nBlueX]= true;
                    maze[nBlueY][nBlueX] = 5;
                    maze[blueY][blueX] = 0;
                    simulation(nRedY, nRedX, nBlueY, nBlueX, cnt+1, maze);
                    blueVisit[nBlueY][nBlueX]= false;
                    maze[nBlueY][nBlueX] = 0;
                    maze[blueY][blueX] = 5;
                }
                redVisit[nRedY][nRedX] = false;
                maze[nRedY][nRedX] = 0;
                maze[redY][redX] = 5;
            }
        }
        
        
        // 파랑 움직이고 빨강 움직임
        if(blueY == eBlueY && blueX == eBlueX){
             for(int i = 0; i < 4;i++){
                int nRedY = redY + dy[i], nRedX = redX + dx[i];
                if(!checkMove(nRedY,nRedX,redVisit,maze)) continue;
                redVisit[nRedY][nRedX] = true;
                maze[nRedY][nRedX] = 5;
                maze[redY][redX] = 0;
                simulation(nRedY, nRedX, blueY, blueX, cnt+1, maze);
                redVisit[nRedY][nRedX]= false;
                maze[nRedY][nRedX] = 0;
                maze[redY][redX] = 5;
             }
        }else{
            for(int i = 0; i < 4; i++){
                int nBlueY = blueY + dy[i], nBlueX = blueX + dx[i];
                if(!checkMove(nBlueY,nBlueX,blueVisit,maze)) continue;
                blueVisit[nBlueY][nBlueX]  = true;
                maze[nBlueY][nBlueX] = 5;
                maze[blueY][blueX] = 0;
                for(int j = 0; j < 4;j++){
                    int nRedY = redY + dy[j], nRedX = redX + dx[j];
                    if(!checkMove(nRedY,nRedX,redVisit,maze)) continue;
                    redVisit[nRedY][nRedX] = true;
                    maze[nRedY][nRedX] = 5;
                    maze[redY][redX] = 0;
                    simulation(nRedY, nRedX, nBlueY, nBlueX, cnt+1, maze);
                    redVisit[nRedY][nRedX] = false;
                    maze[nRedY][nRedX] = 0;
                    maze[redY][redX] = 5;
                }
                blueVisit[nBlueY][nBlueX]  = false;
                maze[nBlueY][nBlueX] = 0;
                maze[blueY][blueX] = 5;
            }
        }
        
    }
    
    
    
    public int solution(int[][] maze) {
        n = maze.length;
        m = maze[0].length;
        blueVisit = new boolean[n][m];
        redVisit = new boolean[n][m];
        
        int redY = 0, redX=0, blueY=0, blueX=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maze[i][j] == 1){
                    redY = i;
                    redX = j;
                    redVisit[i][j] = true;
                    maze[i][j] = 5;
                } else if(maze[i][j] == 2){
                    blueY = i;
                    blueX = j;
                    blueVisit[i][j] = true;
                    maze[i][j] = 5;
                } else if(maze[i][j] == 3){
                    eRedY = i;
                    eRedX = j;
                    maze[i][j] = 0;
                } else if(maze[i][j] == 4){
                    eBlueY = i;
                    eBlueX = j;
                    maze[i][j] = 0;
                }
            }
        }
        
        simulation(redY, redX, blueY, blueX,0,maze);
        
        if(answer == Integer.MAX_VALUE) answer = 0;
        return answer;
    }
}


// public static simulation(int redY, int redX, int blueY, int blueX, int cnt,int[][] maze,int turn, int lastMove){
//         int y,x;
//         boolean[][] visit;
        
//         if(turn == lastMove) return;
//         if(redY == eRedY && redX == eRedX && blueY == eBlueY && blueX == eBlueX){
//             answer = Math.max(cnt,answer);
//             return;
//         }
//         if(turn == 1){
//             y = redY;
//             x = redX;
//             visit = redVisit;
//         } else {
//             y = blueY;
//             x = blueX;
//             visit = blueVisit;
//         }
        
//         boolean moveFlag = false;
//         for(int i = 0; i < 4;i ++){
//             int ny = y + dy[i], nx = x + dx[i];
//             if(!(0 <= ny && ny < n && 0 <= nx && nx < m && maze[ny][nx] == 0 && !visit[ny][nx])) continue;
//             moveFlag = true;
//             visit[ny][nx] = true;
//             maze[ny][nx] = maze[y][x];
//             if(turn == 1) simulation(ny,nx,blueY,blueX,cnt+1,maze, 2, 1);
//             else simulation(redY,redX,ny,nx,cnt+1,maze, 1, 2);
//         }
        
//         if(!moveFlag){
//             if(turn == 1) simulation(y,x,blueY,blueX,cnt+1,maze,2,lastMove);
//             else simulation(redY,redX,y,x,cnt+1,1,lastMove);
//         }
        
//     }