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



vector<pair<int,int> > v;
bool visit[101][101];
int N;

void input() {
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++){
        cin>>v[i].first>>v[i].second;
    }
}

void solution() {
    int ans = 0;
    for(int a=0;a<N;a++)
        for(int i=v[a].first;i<v[a].first+10;i++)
            for(int j=v[a].second;j<v[a].second+10;j++)
                visit[i][j]=true;
        
    
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(visit[i][j]) ans++;
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
