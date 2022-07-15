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

int N,M;
char arr[50][50];

void input() {
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
}

void init() {
}


void solution() {
    /* 숫자 하나를 정사각형으로 취급하므로 최솟값은 1이다 */
    int ans=1;
    
    /* 모든 경우를 다 돌면서 탐색 */
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            /* 정사각형을 찾으므로 N과 M중 작은 값을 골라서 돌면 된다 */
            for(int k=1;k<min(N,M);k++){
                if(k+i<N && k+j<M && arr[k+i][j]==arr[i][j] && arr[i][k+j]==arr[i][j] && arr[k+i][k+j]==arr[i][j]) ans=max(ans,k+1);
            }
        }
    }
    /* ans는 한 변의 길이이므로 제곱을하여 출력 */
    cout<<ans*ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
