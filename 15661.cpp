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

int info[20][20];
int N;
int ans = INT_MAX;
int total = 0;
int check[20];

void cal(int idx, int cnt){
    int teamA = 0;
    int teamB = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(check[i] && check[j]) teamA+=info[i][j];
            else if(!check[i] && !check[j]) teamB+=info[i][j];
        }
    }
    ans = min(ans,abs(teamA - teamB));

    if(cnt > N/2) return;
    if(idx == N) return;

    check[idx] = true;
    cal(idx+1,cnt+1);
    check[idx]=false;
    cal(idx+1,cnt);
}

void input() {
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>info[i][j];
            total+=info[i][j];
        }
    }
    
}

void solution() {
    cal(0,0);
    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
