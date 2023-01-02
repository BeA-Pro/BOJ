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

int cap[52][52];
int flow[52][52];
int path[52];

vector<int> v[52];

int find_index(char c){
    if('A'<=c && c<='Z') return c-'A'+26;
    
    return c-'a';
}

int find_flow(int S,int E){
    int cur = E;
    int ans = INT_MAX;
    
    while(cur!=S){
        ans = min(ans,cap[path[cur]][cur]-flow[path[cur]][cur]);
        cur = path[cur];
    }
    cur = E;
    while(cur!=S){
        flow[path[cur]][cur]+=ans;
        flow[cur][path[cur]]-=ans;
        cur = path[cur];
    }
    
    return ans;
    
}

int edmonds_karp(int S,int E){
    fill(path,path+52,-1);
    queue<int> q;
    q.push(S);
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            if(path[next]<0 && cap[cur][next] - flow[cur][next] > 0){
                q.push(next);
                path[next] = cur;
                if(next == E)
                    return find_flow(S,E);
            }
        }
    }
    
    return 0;
}


void input() {
    int c,n;
    char a,b;
    cin >>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        int i_a = find_index(a);
        int i_b = find_index(b);
        cap[i_a][i_b]+=c;
        cap[i_b][i_a]+=c;
        v[i_a].push_back(i_b);
        v[i_b].push_back(i_a);
    }
}

void init() {
}


void solution() {
    int ans = 0;
    while(1){
        int tmp = edmonds_karp(find_index('A'),find_index('Z'));
        if(tmp==0) break;
        ans+=tmp;
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
