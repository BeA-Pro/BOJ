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

int sum1[1000001];
int sum2[1000001];
string s;


void input() {
    cin>>s;
}

void init() {
}


void solution() {
    int cnt1 = 0, cnt2=0;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') cnt1++;
        else cnt2++;
    }
    
    if(cnt1<cnt2){
        for(int i=0;i<s.size();i++){
            if(i!=0){
                sum1[i]= sum1[i-1];
                sum2[i] = sum2[i-1];
            }
            if(s[i]=='(') sum1[i]++;
            else sum2[i]++;
        }
    }else{
        for(int i=0;i<s.size();i++){
            if(i!=0){
                sum1[i]= sum1[i-1];
                sum2[i] = sum2[i-1];
            }
            if(s[s.size()-1-i]==')') sum1[i]++;
            else sum2[i]++;
        }
    }
    
    for(int i=0;i<s.size();i++){
        if(sum1[i]+1==sum2[i]){
            cout<<sum2[i];
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
