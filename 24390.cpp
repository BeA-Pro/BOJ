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

char c;
int m = 0;
int s = 0;

void input() {
    cin>>c;
    m+=(c - '0');
    cin>>c;
    m = m*10 + (c - '0');
    cin>>c;
    
    cin>>c;
    s+=(c - '0');
    cin>>c;
    s = s*10 + (c - '0');
    
    s+=m*60;
}

void init() {
}


void solution() {
    /*
    if(s==10){
        cout<<2;
    }else if(s == 20){
        cout<<3;
    }else{
    }*/
    
    int cnt = 0;
    bool flag = false;
    while(s){
        if(s>=600) s-=600;
        else if(s>=60) s-=60;
        else if(s>=30){
            s-=30;
            flag = true;
        }
        else s-=10;
        cnt++;
    }
    if(!flag) cnt++;
    // cout<<s;
   
    cout<<cnt;
    
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
