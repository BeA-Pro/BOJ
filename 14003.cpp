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

int N;
vector<int> v;
vector<int> dp;

void input() {
    cin>>N;
    v.resize(N);
    dp.resize(N);
    
    for(int i=0;i<N;i++) cin>>v[i];
}

void init() {
}


void solution() {
    vector<int> L;
    vector <int>::iterator p;
    
    L.push_back(v[0]);
    dp[0] = 1;

    int max_idx = 0, MAX = 0;
    
    for(int i=1;i<N;i++){
        /* 현재 받은 값이 LIS의 마지막 값보다 클 경우 */
        if(L[L.size()-1]<v[i]){
            L.push_back(v[i]);
            dp[i] = L.size();
        }
        else{
            /* 현재 받은 값이 LIS의 마지막 값보다 작을 경우 LIS의 lowerbound를 찾아 교체해 준다.*/
            p = lower_bound(L.begin(),L.end(),v[i]);
            *(p)=v[i];
            dp[i]=p-L.begin()+1;
            
        }
        
        /* 값을 출력할 때 사용해야하므로 dp값이 가장 큰 인덱스를 기억*/
        if(dp[i]>MAX){
            max_idx=i;
            MAX=dp[i];
        }
        
    }
    
    cout<<L.size()<<'\n';
    stack<int> s;
    
    s.push(v[max_idx]);
    
    for(int i=max_idx-1;i>=0;i--){
        if(v[i]<v[max_idx] && dp[i]+1==dp[max_idx]){
            s.push(v[i]);
            max_idx = i;
        }
    }
    
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
