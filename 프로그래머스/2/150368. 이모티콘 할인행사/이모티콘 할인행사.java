class Solution {
    
    void cal(int[][] users, int[] emoticons, int[] discount, int[] answer, int idx){
        if(idx == emoticons.length){
            int total = 0;
            int cnt = 0;
            for(int[]user : users){
                int spend = 0;
                for(int i = 0; i < discount.length; i++){
                    if(discount[i] >= user[0]){
                        spend += emoticons[i] - emoticons[i] / 100 * discount[i];   
                    }
                }
                if(spend >= user[1]) cnt++; // 멤버쉽 가입
                else total+=spend; // 비용 지불
            }
            // for(int dis : discount) System.out.printf("%d ",dis);
            // System.out.println();
            // System.out.printf("cnt %d, total %d\n",cnt,total);
            if(answer[0] < cnt){
                
                answer[0] = cnt;
                answer[1] = total;
            }else if(answer[0] == cnt && answer[1] < total) answer[1] = total;
            return;
        }
        
        for(int i=10;i<=40;i+=10){
            discount[idx] = i;
            cal(users,emoticons,discount,answer,idx+1);
        }
    }
    
    public int[] solution(int[][] users, int[] emoticons) {
        int[] answer = new int []{0,0};
        int[] discount = new int[emoticons.length];
        
        cal(users, emoticons, discount, answer,0);
        
        return answer;
    }
}