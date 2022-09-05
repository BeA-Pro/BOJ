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

int DP[200000];
int W[200000];
int N,M;
ll sum = 0;
int MAX = 0;

void input() {
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>W[i];
        sum+=W[i];
        MAX = max(W[i],MAX);
    }
}

void init() {
}

bool cal(int mid){
    DP[0] = W[0];
    
    for(int i=1;i<N;i++){
        if(i-mid-1>=0){
            DP[i] = max(DP[i-1],W[i] + DP[i-mid-1]);
        }else DP[i] = max(DP[i-1],W[i]);
        
        if(DP[i]>=M) return true;
    }
    
    return false;
}



void solution() {
    if(sum < M){
        cout<<-1;
        return;
    }
    if(MAX >= M){
        cout<<"Free!";
        return;
    }
    //cal(3);
    //for(int i=0;i<N;i++) cout<<DP[i]<<' ';
    
    int left = 0, right = 200000;
    int mid, value, tmp;
    int ans = 0;
    while(left<=right){
        mid = (left + right)/2;
        
        if(cal(mid)){
            ans=max(mid,ans);
            left = mid + 1;
        }else right = mid - 1;
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
