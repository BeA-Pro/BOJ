class Solution {
    int mod = 1234567;
    public int solution(int n) {
        int answer = 0;
        int [] dp = new int[n+1];
        dp[1] = 1;
        for(int i = 2;i<=n;i++) dp[i] = (dp[i-2] + dp[i-1])%mod;
        return dp[n];
    }
}