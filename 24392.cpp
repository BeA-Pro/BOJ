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
#define mod  1000000007

using namespace std;

int N,M;

int MAP[1000][1000];
int DP[1000][1000];

void input() {
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>MAP[i][j];
        }
    }
}

void init() {
}


void solution() {
    for(int i=0;i<M;i++){
        if(MAP[0][i]) DP[0][i] = 1;
    }
    
    for(int i=0;i<N-1;i++){
        for(int j=0;j<M;j++){
            if(MAP[i][j]){
                if(j!=0){
                    if(MAP[i+1][j-1]){
                        DP[i+1][j-1]+=DP[i][j];
                        DP[i+1][j-1]%=mod;
                    }
                }
                if(MAP[i+1][j]){
                    DP[i+1][j]+=DP[i][j];
                    DP[i+1][j]%=mod;
                }
                if(j!=M-1){
                    if(MAP[i+1][j+1]){
                        DP[i+1][j+1]+=DP[i][j];
                        DP[i+1][j+1]%=mod;
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int j=0;j<M;j++){
        ans+=DP[N-1][j];
        ans%=mod;
    }
    
    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
