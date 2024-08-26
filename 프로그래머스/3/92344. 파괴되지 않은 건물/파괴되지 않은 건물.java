class Solution {
    public int solution(int[][] board, int[][] skill) {
        int answer = 0;
        int N = board.length;
        int M = board[0].length;
        int[][] sum = new int[N+1][M+1];
        
        for(int[] i : skill){
            int a = 1;
            if(i[0] == 1) a = -1;
            sum[i[1]][i[2]] += i[5] * a;
            sum[i[1]][i[4]+1] -= i[5] * a;
            sum[i[3]+1][i[2]] -= i[5] * a;
            sum[i[3]+1][i[4]+1] += i[5] * a;
        }
        
        for(int i=0;i<N;i++)
            for(int j=1;j<M;j++) sum[i][j] += sum[i][j-1];
        
            
        for(int j=0;j<M;j++)
            for(int i=1;i<N;i++) sum[i][j] += sum[i-1][j];
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(board[i][j] + sum[i][j] > 0) answer+=1;
            }
        }
        
        return answer;
    }
}