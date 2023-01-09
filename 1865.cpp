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

int cost[501][501];
int ans[501][501];
int N,M,W;

void input() {
    int S,E,T;
    cin>>N>>M>>W;
    //도로 정보
    for(int i=0;i<M;i++){
        cin>>S>>E>>T;
        if(cost[S][E] > T) cost[S][E] = cost[E][S] = T;
    }
    //웜홀 정보
    for(int i=0; i<W;i++){
        cin>>S>>E>>T;
        cost[S][E] = -T;
    }
}

void solution() {
    // 플로이드 와샬, 복제
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            ans[i][j] = cost[i][j];
        }
    }
    // k = 거쳐가는 노드
    for(int k=1;k<=N;k++){
        //  i = 출발 노드
        for(int i=1;i<=N;i++){
            // j = 도착 노드
            for(int j=1;j<=N;j++){
                if(ans[i][k]+ans[k][j]<ans[i][j]) ans[i][j] = ans[i][k] + ans[k][j];
            }
        }
    }

    for(int i=1;i<=N;i++){
        if(ans[i][i]<0){
            cout<<"YES"<<'\n';
            return;
        }
    }
    cout<<"NO"<<'\n';
}

void init(){
    fill(&cost[0][0],&cost[500][501],INF);
    fill(&ans[0][0],&ans[500][501],INF);
    for(int i=1;i<=500;i++) cost[i][i] = 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        init();
        input();
        solution();
    }
    return 0;
}
