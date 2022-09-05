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

set<int> s[300001];
int not_next[300001];
int ans[300001];
int N,M;

void input() {
    cin>>N>>M;
    int a,b;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        s[a].insert(b);
        s[b].insert(a);
    }
}

void init() {
}


void solution() {
    queue<int> q;
    q.push(1);
    int dist = 0;
    
    while(!q.empty()){
        memset(not_next,0,sizeof(int)*(N+1));
        
        int size = q.size();
        
        while(!q.empty()){
            int a = q.front();
            ans[a] = dist;
            q.pop();
            for(auto b : s[a]) not_next[b]++;
        }
        
        for(int i=2;i<=N;i++)
            if(not_next[i]!=size && ans[i] == 0) q.push(i);
        dist++;
    }
    
    cout<<ans[1]<<'\n';
    for(int i=2;i<=N;i++){
        if(ans[i]==0) cout<<-1<<'\n';
        else cout<<ans[i]<<'\n';
    }
    
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
