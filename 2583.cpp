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

int M,N,K;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

bool LAND[101][101];

queue<pair<int,int> > q; /* first : y, second : x */

int bfs(int a,int b){
    int cnt=0; /* 영역 크기 */
    queue<pair<int,int> > q2;
    LAND[a][b]=true;
    q2.push(make_pair(a,b));
    
    while(!q2.empty()){
        int y=q2.front().first, x=q2.front().second;
        q2.pop();
        cnt++;
        for(int i=0;i<4;i++){
            int ny=y+dy[i], nx=x+dx[i];
            if(0<=ny && ny<M && 0<=nx && nx<N && !LAND[ny][nx]){
                LAND[ny][nx]=true;
                q2.push(make_pair(ny,nx));
            }
        }
    }
    return cnt;
}

void input() {
    cin>>M>>N>>K;
    int x1,y1,x2,y2;
    for(int i=0;i<K;i++){
        cin>>x1>>y1>>x2>>y2;
        q.push(make_pair(y1,x1));
        q.push(make_pair(y2,x2));
    }
    
}

void init() {
}


void solution() {
    int x1,y1,x2,y2;
    
    while(!q.empty()){ /* y1,x1 왼쪽 밑에 좌표, y2, x2 오른쪽 위에 좌표 */
        y1=q.front().first, x1=q.front().second;
        q.pop();
        y2=q.front().first, x2=q.front().second;
        q.pop();
        
        /* 사각형이 차지하는 영역을 체크한다. */
        for(int i=y1;i<y2;i++){
            for(int j=x1; j<x2; j++){
                if(!LAND[i][j]) LAND[i][j]=true;
            }
        }
    }
    /* 모든 영역을 돌면서 사각형이 없는 영역의 크기를 구한다. */
    vector<int> ans;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!LAND[i][j]){
                ans.push_back(bfs(i,j));
            }
        }
    }

    sort(ans.begin(),ans.end());
    
    /* 결과 출력 */
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
