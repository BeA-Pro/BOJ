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

bool check[2000001];
int N;
vector<int> v;

void cal(int idx,int value){
    check[value]=true;

    if(idx>=N) return;
    check[v[idx]] = true;

    //현재 경우를 포함 안하는 경우
    cal(idx+1,value);

    //현재 경우를 포함하는 경우
    cal(idx+1,value+v[idx]);
}

void input() {
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) cin>>v[i];
}


void solution() {
    cal(0,0);

    for(int i=0;i<=2000000;i++){
        if(!check[i]){
            cout<<i;
            return;
        }
    }

}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
