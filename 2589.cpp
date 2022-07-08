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

int H,W;
int dy[]={-1,1,0,0};
int dx[]={0,0,1,-1};

vector<string> v;
int check[50][50];
int dist[50][50];

/*점을 탐색할 때마다 초기화*/
void init() {
    fill(&check[0][0],&check[49][50],false);
    fill(&dist[0][0],&dist[49][50],0);
}

/* a,b에서 갈 수 있는 최대 거리를 구해준다.*/
int cal_dist(int a,int b){
    init();
    queue<pair<int,int> > q;
    q.push(make_pair(a,b));
    check[a][b]=true;
    int ans=0;
    
    while(!q.empty()){
        int y=q.front().first, x=q.front().second;
        q.pop();
        ans=max(ans,dist[y][x]);
        for(int i=0;i<4;i++){
            int ny=y+dy[i],nx=x+dx[i];
            if(0<=ny && ny<H && 0<=nx && nx<W && v[ny][nx]=='L'&& !check[ny][nx]){
                check[ny][nx]=true;
                dist[ny][nx]=dist[y][x]+1;
                q.push(make_pair(ny,nx));
            }
        }
    }
    return ans;
}




void input() {
    cin>>H>>W;
    v.resize(H);
    for(int i=0;i<H;i++) cin>>v[i];
}



void solution() {
    int ans=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(v[i][j]=='L'){
                ans=max(ans,cal_dist(i,j));
            }
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
