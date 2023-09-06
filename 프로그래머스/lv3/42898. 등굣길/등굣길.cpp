#include <string>
#include <vector>
#include <iostream>
#define mod 1000000007

using namespace std;
int DP[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    DP[1][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            bool flag = false;
            for(int k = 0; k< puddles.size();k++)
                if(j==puddles[k][0] && i==puddles[k][1]) flag=true;
            
            if(flag) continue;
            DP[i][j] += (DP[i-1][j] + DP[i][j-1])%mod;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<DP[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    return DP[n][m];
}