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

int N;
int bam[200001];
vector<int> tree[200001];

// 처음
bool visit[200001];
// 폭발
bool visit2[200001];

bool bfs(int power){
    queue<pair<int,int> > q;
    queue<int> q2;
    memset(visit,false,sizeof(visit));
    memset(visit2,false,sizeof(visit2));
    
    for(int i=1;i<=N;i++){
        if(!bam[i]){
            visit[i] = true;
            q.push(make_pair(i,0));
        }
    }
    
    while(!q.empty()){
        int cur = q.front().first, p = q.front().second;
        q.pop();
        if(p == power) continue;
        
        int size = tree[cur].size();
        
        for(int i=0;i<size;i++){
            int next = tree[cur][i];
            
            if(!visit[next]){
                visit[next] = true;
                q.push(make_pair(next,p+1));
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        if(bam[i] && !visit[i]) q2.push(i);
    }
    
    while(!q2.empty()){
        int q2_size = q2.size();
        bool flag = false;
        
        while(q2_size--){
            
            int cur = q2.front(); q2.pop();
            int size = tree[cur].size();
            if(visit2[cur]) continue;
            visit2[cur] = true;
            for(int i=0;i<size;i++){
                int next = tree[cur][i];
                if(bam[next] && !visit2[next]) q2.push(next);
                if(!bam[next]) flag = true;
            }
        }
        
        if(flag) break;
        
    }
    
    for(int i=1;i<=N;i++){
        if(bam[i] && !visit2[i]) return false;
    }
    
    return true;
}

void input() {
    int a,b;
    cin>>N;
    for(int i=1;i<=N;i++) cin>>bam[i];
    
    for(int i=1;i<=N-1;i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}

void init() {
}


void solution() {
    
    int left = 0, right = 200020;
    int ans = 0;
    while(left<=right){
        int mid = (left + right)/2;
        if(bfs(mid)){
            // cout<<"mid "<<mid<<'\n';
            ans = max(ans,mid);
            left = mid + 1;
        }else right = mid - 1;
    }
    
    cout<<ans + 1;
    
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
