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
int in_degree[501];/*진입차수*/
int T[501]; /*건물을 짓는데 걸리는 시간*/
int ans[501]; /*건물을 짓는데 걸리는 최소 시간*/

vector<int> G[501];


void input() {
    cin>>N;
    int time,from;
    for(int i=1;i<=N;i++){
        cin>>T[i];
        while(1){
            cin>>from;
            if(from==-1) break;
            G[from].push_back(i);
            in_degree[i]++;
        }
    }
}

void init() {
}


void solution() {
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(in_degree[i]==0){ /* 진입 차수가 0인 것을 큐에 넣어준다. */
            q.push(i);
        }
    }
    
    for(int i=1;i<=N;i++){
        int from = q.front();
        ans[from]+=T[from];
        q.pop();
        
        for(int j=0;j<G[from].size();j++){
            int to = G[from][j];
            if(--in_degree[to]==0) q.push(to); /* 진입 차수가 0인 것을 큐에 넣어준다. */
            if(ans[from]>ans[to]) ans[to]=ans[from]; /* 만약 현재까지 걸린 시간이 더 오래 걸렸다면 값을 바꿔준다. */
        }
    }
    
    for(int i=1;i<=N;i++) cout<<ans[i]<<'\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
