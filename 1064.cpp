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

pair<long double,long double> A,B,C;

long double getLength(pair<long double,long double> a, pair<long double,long double> b){
    long double x = a.first - b.first;
    long double y = a.second - b.second;
    return sqrt(x*x + y*y);
}

long double getInclination(pair<long double,long double> a, pair<long double,long double> b){
    return abs(a.second - b.second)/abs(a.first - b.first);
}

void input() {
    cin>>A.first>>A.second>>B.first>>B.second>>C.first>>C.second;
}

void solution() {
    if(getInclination(A,B) == getInclination(B,C)){
        cout<<"-1.0";
        return;
    }

    long double lenA = 2.0*(getLength(A,B)+getLength(B,C));
    long double lenB = 2.0*(getLength(A,C)+getLength(B,C));
    long double lenC = 2.0*(getLength(A,C)+getLength(A,B));

    cout<<max({lenA,lenB,lenC})-min({lenA,lenB,lenC});
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed;
	cout.precision(16);
    input();
    solution();
    return 0;
}
