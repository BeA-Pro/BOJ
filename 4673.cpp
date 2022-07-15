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

bool check[10001];

void input() {
}

void init() {
}


void solution() {
    /* 모든 경우를 돌면서 값 확인 */
    for(int i=1;i<=10000;i++){
        if(!check[i]){
            cout<<i<<'\n';
            int x=i;
            
            while(1){
                int tmp=x;
                int sum=0;
                
                /* 새로운 d(n) 구하기 */
                while(tmp>0){
                    sum+=(tmp%10);
                    tmp/=10;
                }
                x+=sum;
                
                /* 10000을 넘어가면 탐색 중지 */
                if(x>10000)break;
                
                /* 이미 방문한 곳이라면 더 이상 확인 할 필요 없음 */
                if(check[x]) break;
                check[x]=true;
            }
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
