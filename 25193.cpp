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

void input() {
}

void init() {
}


void solution() {
    int N;
    cin>>N;
    int cnt=0,cnt2=1;
    bool flag = false;
    for(int i=0;i<N;i++){
        char c;
        cin>>c;
        if(c=='C'){
            cnt++;
        }else cnt2++;
    }
    
    int sum=cnt/(cnt2);
    if(cnt%cnt2!=0) sum++;
    
    cout<<sum;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
