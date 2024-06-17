class Solution {
    
    public int solution(int storey) {
        int answer = 0;
        // int num = storey%10;
        // answer = cal(storey - num) + num;
        // answer = Math.min(answer, cal(storey - num + 10) + 10 - num);
        while(storey != 0){
            int one = storey % 10;
            if(one < 5){
                answer += one;
            }else if (one > 5){
                answer+= 10 - one;
                storey+=10;
            }else{
                int ten = (storey % 100 - one)/10;
                if(ten < 5){
                    answer += one;
                }else{
                   answer+= 10 - one;
                    storey+=10; 
                }
            }
            storey/=10;  
        }
        return answer;
    }
}