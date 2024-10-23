class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;
        int right = 0, left = 1;
        int n = diffs.length;
        
        for(int diff : diffs) right = Math.max(right,diff);
        answer = right;
        
        while(left<=right){
            int level = (left+right)/2;
            long sum = times[0];
            
            for(int i=1;i<n;i++){
                if(level>=diffs[i]) sum+=(long)times[i];
                else sum+= ((times[i]+times[i-1])*(diffs[i]-level)+times[i]);
            }
            
            
            if(sum <= limit){
                answer = Math.min(answer, level);
                right = level-1;
            }
            else left = level+1;
            
        }
        return answer;
    }
}