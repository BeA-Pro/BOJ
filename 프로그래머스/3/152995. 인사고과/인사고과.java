import java.util.*;

class Solution {
    public int solution(int[][] scores) {
        int answer = 1;
        int[] wanho = scores[0].clone();
        
        
        Arrays.sort(scores, (a,b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        
        int max = scores[0][1];
        
        for(int[] score : scores){
            // System.out.printf("%d %d\n",score[0],score[1]);
            if(wanho[0] < score[0] && wanho[1] < score[1]) return -1;
            
            if(score[1] >= max){
                max = score[1];
                if(score[1] + score[0] > wanho[1] + wanho[0]) answer+=1;
            }
        }
        
        
        return answer;
    }
}