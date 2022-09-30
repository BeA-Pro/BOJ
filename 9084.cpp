#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <set>

#define p(a, b) make_pair(a, b)
#define SWAP(a, b, type) do { \
    type temp; \
    temp = a;  \
    a = b;     \
    b = temp;  \
} while (0)
#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

ll dp[10001];
ll coin[20];
int T,N,M;

void input() {
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>coin[i];
        dp[coin[i]] = 1;
    }
    cin>>M;
    
}

void init() {
}


void solution() {
    for(int i=0;i<N;i++){
        for(int j=1;j<=M:j++){
            if(j%coin[i] == 0 && j>coin[i]) dp[j]+=
        }
    }
    for(int i=1;i<=M;i++){
        dp[i]+=dp[i-1];
        for(int j=0;j<N;j++){
            if(i>coin[j] && i%coin[j]==0) dp[i]+=(dp[i-coin[j]] * i/coin[j]);
        }
    }
    
    cout<<dp[M]<<'\n';
    
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        input();
        solution();
    }
    return 0;
}
