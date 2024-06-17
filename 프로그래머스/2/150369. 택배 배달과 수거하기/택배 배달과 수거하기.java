class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;
        int del = 0;
        int pic = 0;
        
        for(int i = deliveries.length-1;i>=0;i--){
            del += deliveries[i];
            pic += pickups[i];
            
            while(del > 0 || pic > 0){
                del-=cap;
                pic-=cap;
                answer+=(i+1)*2;
            }
        }
        return answer;
    }
}