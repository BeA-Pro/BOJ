class Solution {
    static int answer = -1;
    static int n, m;
    static int[] dy = {-1,1,0,0};
    static int[] dx = {0,0,-1,1};
    
    static int bfs(int[][] board, int[] cur, int[] nxt){
        if(board[cur[0]][cur[1]] == 0) return 0;
        board[cur[0]][cur[1]] = 0;
        int res = 0;

        for(int i=0;i<4;i++){
            int ny = dy[i] + cur[0], nx = dx[i] + cur[1];
            if(0<= ny && ny < n && 0 <= nx && nx < m && board[ny][nx] == 1){
                int nxt_res = bfs(board,nxt, new int[] {ny,nx}) + 1;
                
                if(res % 2 == 0 && nxt_res % 2 == 1) res = nxt_res;
                else if(res % 2 == 0 && nxt_res % 2 == 0) res = res > nxt_res ? res : nxt_res;
                else if(res % 2 == 1 && nxt_res % 2 == 1) res = res < nxt_res ? res : nxt_res;
            }
        }
        
        board[cur[0]][cur[1]] = 1;
        
        return res;
    }
    
    public int solution(int[][] board, int[] aloc, int[] bloc) {
        n = board.length;
        m = board[0].length;
        
        
        return bfs(board,aloc,bloc);
    }
}