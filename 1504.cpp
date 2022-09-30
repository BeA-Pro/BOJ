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
#include <string.h>

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

bool visit[801];
vector<pair<int,int> > tree[801];
vector<int> v,v2;
int total_cost[801];
int ans = 0,ans2= 0;
int N,E;

int dijstra(int START, int END){
    //cout<<"START "<<START<<" END "<<END<<'\n';
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({0,START});
    
    while(!pq.empty()){
        int cur = pq.top().second, cost = pq.top().first; pq.pop();
        //cout<<"cur "<<cur<<'\n';
        if(visit[cur]) continue;
        
        if(cur == END) return cost;

        visit[cur] = true;
        
        for(auto i : tree[cur]){
            int next = i.second, next_cost = i.first;
            //cout<<"next "<<next<<'\n';
            // cout<<total_cost[next]<<'\n';
            if(!visit[next] && total_cost[next] > next_cost + cost){
                total_cost[next] = next_cost + cost;
                pq.push({total_cost[next],next});
            }
        }
    }
    
    return -1;
}

void input() {
    cin>>N>>E;
    int s,e,c;
    
    int a1,a2;
    
    for(int i=0;i<E;i++){
        cin>>s>>e>>c;
        tree[s].push_back({c,e});
        tree[e].push_back({c,s});
    }
    cin>>a1>>a2;
    
    v.push_back(1);
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(N);
    
    v2.push_back(1);
    v2.push_back(a2);
    v2.push_back(a1);
    v2.push_back(N);
}

void init() {
}


void solution() {
    int tmp;
    for(int i=0;i<3;i++){
        fill(&total_cost[0],&total_cost[801],INT_MAX);
        fill(&visit[0],&visit[801],false);
        tmp = dijstra(v[i],v[i+1]);
        if(tmp == -1){
            cout<<tmp;
            return;
        }
        ans+=tmp;
    }
    for(int i=0;i<3;i++){
        fill(&total_cost[0],&total_cost[801],INT_MAX);
        fill(&visit[0],&visit[801],false);
        tmp = dijstra(v2[i],v2[i+1]);
        if(tmp == -1){
            cout<<tmp;
            return;
        }
        ans2+=tmp;
    }
    cout<<min(ans,ans2);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
