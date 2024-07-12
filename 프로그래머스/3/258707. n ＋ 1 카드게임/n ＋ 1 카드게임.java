import java.util.*;

class Solution {
    public int solution(int coin, int[] cards) {
        int answer = 1;
        int n = cards.length;
        
        ArrayList<PriorityQueue<Integer>> pqList = new ArrayList<>();
        for(int i=0;i<n; i++) pqList.add(new PriorityQueue<Integer>());
        
        boolean[] visit = new boolean[n];
        int[] round = new int[n];
        
        for(int i=0;i<n/3;i++) round[i] = 0;
        int a = 2;
        
        for(int i=n/3; i<n;i++) round[i] = (a++)/2;
        
        
        for(int i=0;i<n;i++){
            if(visit[i]) continue;
            
            int c = 0;
            if(round[i] > 0) c += 1;
            
            for(int j=i+1;j<n;j++){
                if(cards[i] + cards[j] == n + 1){
                    visit[j] = true;
                    if(round[j] > 0) c+=1;
                    pqList.get(round[j]).add(c);
                    break;
                }
            }
        }
        
        int pos_round = 1;
        while(true){
            int g_round = -1, req_coin = Integer.MAX_VALUE;
            boolean flag = false;
            pos_round-=1;
            
            for(int i=0;i<=Math.min(answer,round[n-1]);i++){
                if(pqList.get(i).isEmpty()) continue;
                else flag = true;
                if(pqList.get(i).peek() < req_coin){
                    g_round = i;
                    req_coin = pqList.get(i).peek();
                }
                
            }
            
            if(!flag){
                break;
            }
            
            if(req_coin <= coin){
                coin-=req_coin;
                pos_round+=1;
                pqList.get(g_round).poll();
            }
            
            if(pos_round==0) break;
            
            answer+=1;
        }
        
        
        return Math.min(round[n-1]+1,answer);
    }
}