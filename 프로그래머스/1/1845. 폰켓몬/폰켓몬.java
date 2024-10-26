import java.util.*;
class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        Set<Integer> s = new HashSet<>();
        
        int n = nums.length;
        
        for(int num : nums) s.add(num);
        
        answer = Math.min(n/2,s.size());
        
        return answer;
    }
}