import java.util.*;


class Solution {
    public int solution(int n, int k, int[] enemy) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->b-a);
        
        for(;answer<enemy.length;answer++){
            pq.add(enemy[answer]);
            n-=enemy[answer];
           // System.out.println(n+" "+k);
            if(n >= 0) continue;
            if(k == 0) break;
            n+=pq.poll();
            k-=1;
        }
        
        return answer;
    }
}