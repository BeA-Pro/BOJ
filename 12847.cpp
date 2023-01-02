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

void input() {
}

void init() {
}


void solution() {
    ll n, m;
    cin>>n>>m;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    ll ans = 0;
    ll sum = 0;
    
    queue<ll> q;
    for(int i=0;i<n;i++){
        sum+=v[i];
        q.push(v[i]);
        if(q.size() == m){
            ans = max(ans,sum);
            sum-=q.front();
            q.pop();
        }
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
