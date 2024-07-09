import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int [] coins = new int [n];

        int total = 0;
        int mod = 1000000;
        for(int i=0;i<n;i++){
            coins[i] = Integer.parseInt(br.readLine());
            total+=coins[i];
        }

        int max_sum = total/2;
        int[] count = new int [max_sum + 1];
        boolean[] dp = new boolean[max_sum + 1];
        count[0] = 1;
        dp[0] = true;
        for(int coin : coins){
            for(int i = max_sum; i>=coin; i--){
                if(dp[i-coin]) {
                    dp[i] = true;
                    count[i] = (count[i] + count[i - coin]) % mod;
                }
            }
        }

        int sum = 0;
        for(int i = max_sum; i>=0;i--) {
            if (dp[i]) {
                sum = i;
                break;
            }
        }

        System.out.println(total - sum*2);
        System.out.println(count[sum]);

    }
}
