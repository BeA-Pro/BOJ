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
string formula;
int N;
int ans = INT_MIN;

int cal(int a, int b, char oper){
    if(oper == '+') return a+b;
    if(oper == '*') return a*b;
    return a-b;
}


void DFS(int idx, int value){
    if(idx > N-1){
        ans = max(value,ans);
        return;
    }

    char oper = idx==0 ? '+' : formula[idx-1];

    // 이전 수식 괄호 계산
    if(idx < N-2){
        int bracket = cal(formula[idx]-'0',formula[idx+2]-'0',formula[idx+1]);
        DFS(idx+4,cal(value,bracket,oper));
    }
    DFS(idx+2,cal(value,formula[idx]-'0',oper));
}

void input() {
    cin>>N;
    cin>>formula;
}

void solution() {
    DFS(0,0);
    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
