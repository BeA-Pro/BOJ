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

vector<int> A;
vector<int> B;

int A_size,B_size;

void input() {
    cin>>A_size>>B_size;
    A.resize(A_size);
    B.resize(B_size);
    for(int i=0;i<A_size;i++) cin>>A[i];
    for(int i=0;i<B_size;i++) cin>>B[i];
}

void init() {
}


void solution() {
    int point1 = 0, point2 = 0;
    vector<int> result;
    while(point1<A_size && point2<B_size){
        if(A[point1]>B[point2]) result.push_back(B[point2++]);
        else result.push_back(A[point1++]);
    }
    
    if(point1!=A_size)
        while(point1<A_size) result.push_back(A[point1++]);
    else
        while(point2<B_size) result.push_back(B[point2++]);
    
    for(int i=0;i<result.size();i++) cout<<result[i]<<' ';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
