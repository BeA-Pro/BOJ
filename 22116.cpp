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
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
bool visit[1000][1000];
int dist[1000][1000];
int arr[1000][1000];
int N;

struct cmp{
    bool operator()(tuple<int,int,int> a,tuple<int,int,int> b){
        return get<0>(a) > get<0>(b);
    }
};

void input() {
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j =0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    fill(&dist[0][0],&dist[N-1][N],INF);
}

void init() {
}


void solution() {
    priority_queue< tuple<int,int,int>, vector<tuple<int,int,int> >, cmp > pq;
    pq.push({0,0,0});
    
    if(N==1){
        cout<<0;
        return;
    }
    
    while(!pq.empty()){
        int cost = get<0>(pq.top()), y = get<1>(pq.top()), x = get<2>(pq.top());
        pq.pop();
        for(int i=0;i<4;i++){
            int ny = dy[i]+y, nx = dx[i]+x;
            if(0<=ny && ny<N && 0<=nx && nx<N){
                int next=max(abs(arr[ny][nx]-arr[y][x]),cost);
                if(dist[ny][nx] > next){
                    dist[ny][nx]=next;
                    pq.push({next,ny,nx});
                }
                
                
            }
        }
        
    }
    cout<<dist[N-1][N-1];
    
    
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}

