import java.util.*;

class Solution {
    public int solution(int[][] data, int col, int row_begin, int row_end) {
        int answer = 0;
        Arrays.sort(data,new Comparator<int []>(){
            @Override
            public int compare(int[] o1, int[] o2){
                if(o1[col - 1] == o2[col - 1]){
                    return o2[0] - o1[0]; // 기본키 기준 내림차순
                } else{
                    return o1[col - 1] - o2[col - 1]; // col - 1 기준 오름차순
                }
            }
        });
        
        for(int i=row_begin-1;i<row_end;i++){
            int sum = 0;
            for(int j = 0; j < data[i].length; j++) sum += data[i][j] % (i + 1);
            answer ^= sum;
        }
        
        return answer;
    }
}