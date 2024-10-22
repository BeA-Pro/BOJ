// d : 아, l : 왼, r : 오, u, 위

class Solution {
    static int[] dy ={1,0,0,-1}, dx = {0,-1,1,0};
    static boolean[][][] visit;
    static StringBuilder sb = new StringBuilder();
    static String answer = "impossible";
    static boolean flag = false;
    
    static void dfs(int n, int m,int y,int x, int r, int c, int k, int cnt){
        if( k == cnt){
            if(!flag && r == y && c == x){
                flag = true;
                answer = sb.toString();
            }
            return;
        }
        visit[y][x][cnt] = true;
        
        for(int i=0;i<4;i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(0 <= ny && ny < n && 0 <= nx && nx < m && !visit[ny][nx][cnt + 1] && !flag){
                if(i == 0) sb.append("d");
                else if(i == 1) sb.append("l");
                else if(i == 2) sb.append("r");
                else sb.append("u");
                dfs(n,m,ny,nx,r,c,k,cnt+1);
                sb.deleteCharAt(sb.length()-1);
            }
        }
    }
    
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        
        visit = new boolean[n][m][k+1];
        
        dfs(n,m,x-1,y-1,r-1,c-1,k,0);
        
        
        return answer;
    }
}