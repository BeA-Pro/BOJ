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

string s;
int prefix[3][200001]; // 0 : C, 1 : O, 2 : W

void input() {
    cin>>s;
}

void init() {
}


void solution() {
    for(int i=1;i<=s.size();i++){
        if(s[i-1]=='C') prefix[0][i] = 1;
        else if(s[i-1]=='O') prefix[1][i] = 1;
        else prefix[2][i] = 1;
        
        
        for(int j=0;j<3;j++) prefix[j][i]+=prefix[j][i-1];
        
    }
    
    int q; cin>>q;
    int s,e;
    for(int i=0;i<q;i++){
        cin>>s>>e;
        int c_cnt = prefix[0][e] - prefix[0][s-1];
        int o_cnt = prefix[1][e] - prefix[1][s-1];
        int w_cnt = prefix[2][e] - prefix[2][s-1];
        if(c_cnt%2==1 && o_cnt%2 == 0 && w_cnt%2 == 0) cout<<'Y';
        else if(c_cnt%2 ==0 && o_cnt%2 == 1 && w_cnt%2 == 1) cout<<'Y';
        else cout<<'N';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
