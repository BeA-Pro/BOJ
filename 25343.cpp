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

int m[100][100];
int DP[100][100];
int dy[] = {0,1};
int dx[] = {1,0};

int n;

int get_dp(int val,vector<int> v, vector<pair<int,int> > pos){
    for(int i=v.size()-1;i>=0;i--){
        if(val>v[i]) return DP[pos[i].first][pos[i].second]+1;
        if(val==v[i]) return DP[pos[i].first][pos[i].second];
    }
    return 1;
}

void dfs(int y, int x, vector<int> &v, vector<pair<int,int> > &pos){
    v.push_back(m[y][x]);
    pos.push_back(make_pair(y,x));
    
    for(int i = 0;i<2;i++){
        int ny = dy[i] + y, nx = dx[i] + x;
        if(0<= ny && ny<n && 0<=nx && nx<n){
            int tmp = get_dp(m[ny][nx],v,pos);
            
            //cout<<ny<<' '<<nx<<' '<<tmp<<'\n';
            //if(DP[ny][nx]<tmp){
            if(DP[ny][nx]<tmp) DP[ny][nx] = tmp;
            if(ny!=n-1 || nx!=n-1) dfs(ny,nx,v,pos);
            //}
        }
    }
    v.pop_back();
    pos.pop_back();
}

void input() {
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>m[i][j];
    }
}

void init() {
}


void solution() {
    DP[0][0]=1;
    vector<int> v;
    vector<pair<int,int> > pos;
    dfs(0,0,v,pos);
    cout<<DP[n-1][n-1];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
