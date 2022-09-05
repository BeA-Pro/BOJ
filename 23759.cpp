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

int N,K;
vector<string> v;
int dp[10][26]; // dp[x][y]는 인덱스가 x이고 알파벳이 y일 때, 비슷한 문자열의 최대 갯수

void input() {
    cin>>N>>K;
    string s;
    for(int i=0;i<N;i++){
        cin>>s;
        v.push_back(s);
    }
}

void init() {
}


void solution() {
    int ans = 0;
    for(int i=0;i<N;i++){
        vector<pair<int,int> > change_index;
        int max_cnt = 0;
        
        for(int j=0;j<K;j++){
            int index = v[i][j] - 'a';
            change_index.push_back({j,index});
            max_cnt = max(dp[j][index] + 1, max_cnt);
        }
        
        for(int j=0;j<change_index.size();j++) dp[change_index[j].first][change_index[j].second] = max_cnt;
        ans = max(ans,max_cnt);
        
    }
    cout<<N-ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
