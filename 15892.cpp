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

vector<int> v[301];

int cap[301][301];
int flow[301][301];
int path[301];

int n,m;

int get_flow(int S,int E){
    int f = INT_MAX;
    int cur = E;
    
    while(cur!=S){
        f = min(f,cap[path[cur]][cur]-flow[path[cur]][cur]);
        cur = path[cur];
    }
    cur = E;
    while(cur!=S){
        flow[path[cur]][cur]+=f;
        flow[cur][path[cur]]-=f;
        cur = path[cur];
    }
    
    return f;
}

int edmonds_karp(int S,int E){
    fill(path,path+301,-1);
    queue<int> q;
    q.push(S);
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            if(path[next]<0 && cap[cur][next] - flow[cur][next]>0){
                path[next]=cur;
                q.push(next);
                if(next == E) return get_flow(S,E);
            }
        }
    }
    
    return 0;
}


void input() {
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        v[a].push_back(b);
        v[b].push_back(a);
        cap[a][b] += c;
        cap[b][a] += c;
    }
}

void init() {
}


void solution() {
    int max_flow=0;
    
    while(1){
        int tmp = edmonds_karp(1,n);
        if(tmp==0) break;
        max_flow+=tmp;
    }
    cout<<max_flow;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
