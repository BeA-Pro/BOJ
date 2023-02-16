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
ll N,K;

vector<pair<ll,ll > > gem;
vector<ll> bag;
priority_queue<ll> pq;
bool check[300001];

void input() {
    cin>>N>>K;
    gem.resize(N);
    bag.resize(K);
    for(int i=0;i<N;i++) cin>>gem[i].first>>gem[i].second;
    for(int i=0;i<K;i++) cin>>bag[i];
}

void solution() {
    ll ans=0;
    sort(gem.begin(),gem.end());
    sort(bag.begin(),bag.end());

    int idx = 0;
    for(int i=0;i<K;i++){
        while(idx<N && gem[idx].first<=bag[i])
            pq.push(gem[idx++].second);

        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
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

