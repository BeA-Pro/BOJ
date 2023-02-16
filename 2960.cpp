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

bool v[1001];
int N,K;

void input() {
    cin>>N>>K;
}

void solution() {
    int cnt = 0;
    for(int i=2;i<N+1;i++){
        int tmp = i;
        while(tmp<N+1){
            if(!v[tmp]){
                v[tmp]=true;
                cnt++;
            }
            if(cnt==K){
                cout<<tmp;
                return;
            }
            tmp+=i;
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
