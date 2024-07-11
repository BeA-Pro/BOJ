class Solution {
    public int solution(int n, int[] tops) {
        int answer = 0;
        int [][] dp = new int[n][2]; // 0 일 경우 오른쪽 존재, 1일 경우 오른쪽 존재 x
        int mod = 10007;
        if(tops[0] == 1){
            dp[0][0] = 1;
            dp[0][1] = 3;
        }else{
            dp[0][0] =1;
            dp[0][1] = 2;
        }
        
        for(int i=1;i<n;i++){
            if(tops[i] == 1){ // top이 존재 할 때
                dp[i][0] = ((dp[i-1][0] * 1) + (dp[i-1][1] * 1))%mod;
                dp[i][1] = ((dp[i-1][0] * 2) + (dp[i-1][1] * 3))%mod;
            }else{
                dp[i][0] = ((dp[i-1][0] * 1) + (dp[i-1][1] * 1))%mod;
                dp[i][1] = ((dp[i-1][0] * 1) + (dp[i-1][1] * 2))%mod;
            }
        }
        // for(int[] a : dp){
        //     System.out.println(a[0] + " "+ a[1]);
        // }
        return (dp[n-1][0] + dp[n-1][1])%mod;
    }
}