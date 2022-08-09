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
vector<int> v;
vector<int> result;

int r = 0, l = 0;

void input() {
    cin>>N>>M;
    v.resize(N);
    result.resize(M);
    
    for(int i=0;i<N;i++){
        cin>>v[i];
        r +=v[i];
        l = max(l,v[i]);
    }
}

void init() {
}


void solution() {
    int ans = r;
    
    
    while(l<=r){
        int mid = (l+r)/2;
        
        int group_cnt = 0, sum = 0;
        
        vector<int> tmp;
        
        for(int i=0;i<N;i++){
            
            
            if(sum+v[i] > mid){
                tmp.push_back(group_cnt);
                sum = v[i];
                group_cnt=1;
                
            }else{
                sum+=v[i];
                group_cnt++;
            }
            
        }
        
        tmp.push_back(group_cnt);
        
        /*
         cout<<mid<<' '<<tmp.size()<<'\n';
         for(int i=0;i<tmp.size();i++) cout<<tmp[i]<<' ';
         cout<<'\n';*/
        
        if(tmp.size() <= M){
            
            if(ans > mid){
                ans = mid;
                for(int i=0;i<tmp.size();i++) result[i] = tmp[i];
            }
            
            r = mid-1;
            
        }else if(tmp.size() > M) l = mid+1;
        else r = mid-1;
        
    }
    
    cout<<ans<<'\n';
    
    int i, sum = 0, marbleCnt = 0;
    for (i=0; i < N; i++) {
        sum += v[i];
        if (sum > ans) {
            sum = v[i];
            M--;
            cout << marbleCnt << " ";
            marbleCnt = 0;
        }
        marbleCnt++;
        // M개의 그룹을 만들기 위해 최소한의 구슬은 남겨둡니다.
        // (나머지 그룹에 적어도 구슬 1개를 배치해야 하기 때문.)
        if (N - i == M) break;
    }
    
    // 위에서 구한 구슬 개수를 현재 그룹까지만 출력하고
    // 나머지 남은 그룹에는 구슬 1개씩 배치
    while (M--){
        cout << marbleCnt << " ";
        marbleCnt = 1;
    }
    
    
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
