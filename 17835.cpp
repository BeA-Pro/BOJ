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

int N,M,K;
bool end_point[100001];
vector<tuple<ll,ll> > tree[100001];
bool visit[100001];

struct cmp{
    bool operator()(tuple<ll,ll> a,tuple<ll,ll> b){
        return get<0>(a) > get<0>(b);
    }
};

void dijkstra() {

    ll ans_cost=0,ans_node=0;
    
    priority_queue< tuple<ll,ll>, vector<tuple<ll,ll> >, cmp > pq;
    
    for(int i=1;i<=N;i++){
        if(!end_point[i]) continue;
        pq.push({0,i});
        
    }
    
    while(!pq.empty()){
        ll cost = get<0>(pq.top()), cur = get<1>(pq.top()); pq.pop();
        
        if(visit[cur]) continue;
        visit[cur] = true;
        
        if(ans_cost < cost || ans_cost == cost && ans_node > cur){
            ans_cost = cost;
            ans_node = cur;
        }
        
        
        for(int j=0;j<tree[cur].size();j++){
            ll next = get<1>(tree[cur][j]), total_cost = get<0>(tree[cur][j])+cost;
            if(visit[next]) continue;
            pq.push({total_cost,next});
        }
        
    }
    
    
    cout<<ans_node<<'\n';
    cout<<ans_cost;
}



void input() {
    cin>>N>>M>>K;
    int s,e,c;
    for(int i=0;i<M;i++){
        cin>>s>>e>>c;
        tree[e].push_back({c,s});
    }
    for(int i=0;i<K;i++){
        cin>>e;
        end_point[e]=true;
    }
}

void init() {
}


void solution() {
    dijkstra();
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
