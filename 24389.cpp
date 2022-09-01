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

// unsigned int a = INT_MAX;
unsigned int b;
unsigned int n_b;


void input() {
    cin>>b;

}

void init() {
}


void solution() {
    n_b = ~b;
    n_b++;
    
    // cout<<n_b<<"\n";
    unsigned int c = n_b ^ b;
    //unsigned int t = 2;

    // cout<<c<<'\n';
    int cnt = 0;
    while(c!=0){
        if(c%2==1) cnt++;
        c/=2;
        // cout<<c<<'\n';
    }
    cout<<cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
