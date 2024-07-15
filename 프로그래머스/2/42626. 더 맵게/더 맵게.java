import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int i : scoville) pq.add(i);
        int cnt = 0;
        
        while(pq.size()!=1 && pq.peek() < K){
            pq.add(pq.remove() + pq.remove()*2);
            cnt++;
        }
        
        if(pq.peek() >= K) return cnt;
        
        return -1;
    }
}