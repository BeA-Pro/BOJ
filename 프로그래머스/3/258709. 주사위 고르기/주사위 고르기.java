class Solution {
    static int[] answer;
    static int ans_sum = 0;
    static int n = 0;
    static boolean[] visit;
    
    void dfs(int idx,int[] sum,int[] side,int cnt, int[][] dice){
        for(int i=0;i<6;i++){
            if(idx+1!=n/2){
                dfs(idx+1,sum,side,cnt+dice[side[idx]][i],dice);
            }else sum[cnt+dice[side[idx]][i]]+=1;
        }
    }
    
    void cal(int idx,int cnt,int[][] dice){
        if(cnt == n/2){
            int[] a_side = new int[n/2];
            int[] b_side = new int[n/2];
            int a_idx = 0, b_idx = 0;
            for(int i=0;i<n;i++){
                if(visit[i]) a_side[a_idx++] = i;
                else b_side[b_idx++] = i;
            }
            int[] a_sum = new int[100*(int)Math.pow(6, n/2)+1];
            int[] b_sum = new int[100*(int)Math.pow(6, n/2)+1];
            
            dfs(0,a_sum,a_side,0,dice);
            dfs(0,b_sum,b_side,0,dice);
            
            // for(int i=0;i<a_sum.length;i++){
            //     if(a_sum[i] != 0) System.out.printf("%d %d\n", i,a_sum[i]);
            // }
            // System.out.println();
            // for(int i=0;i<b_sum.length;i++){
            //     if(b_sum[i] != 0) System.out.printf("%d %d\n", i,b_sum[i]);
            // }
            
            for(int i=1;i<b_sum.length;i++) b_sum[i] += b_sum[i-1];
            int total = 0;
            
            // for(int i=0;i<a_sum.length;i++){
            //     if(a_sum[i] != 0) System.out.printf("%d %d\n", i,a_sum[i]);
            // }
            // System.out.println();
            // for(int i=0;i<b_sum.length;i++){
            //     if(b_sum[i] != 0) System.out.printf("%d %d\n", i,b_sum[i]);
            // }
            
            for(int i=1;i<a_sum.length;i++){
                if(a_sum[i]!=0){
                    total+=a_sum[i]*b_sum[i-1];
                }
            }
            
            if(total > ans_sum){
                ans_sum = total;
                answer = a_side;
                
                // for(int a : a_side) System.out.printf("%d ",a);
                // System.out.println();
                // System.out.println(ans_sum);
            }
            
            return;
        }
        if(idx==n) return;
        
        visit[idx] = true;
        cal(idx+1,cnt+1,dice);
        visit[idx] = false;
        cal(idx+1,cnt,dice);
    }
    
    public int[] solution(int[][] dice) {
        n = dice.length;
        visit = new boolean[n];
        
        cal(0,0,dice);
        
        for(int i=0;i<answer.length;i++) answer[i]++;
        return answer;
    }
}