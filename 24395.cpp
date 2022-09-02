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
#include <tuple>

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

bool cmp(tuple<int,int,int> a,tuple<int,int,int> b){
    return get<2>(a) < get<2>(b);
}




ll dp[101][51][51];
ll make[101][51][51];
ll N,M;

vector<tuple<ll,ll,ll> >v;



void input() {
    cin>>N>>M;
    v.resize(M+1);
    for(int i=1;i<=M;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        v[i] = {a,b,c};
    }
}

void init() {
}


void solution() {

    make[0][0][0] = true;
    
    
    for(ll k=1;k<=M;k++){
        ll red = get<0>(v[k]), blue = get<1>(v[k]), danger = get<2>(v[k]);
        for(ll i=0;i<=50;i++){
            for(ll j=0;j<=50;j++){
                
                // 이전에 i,j를 만들 수 있었다면 dp값을 가져오고 만들 수 있다고 체크한다.
                if(make[k-1][i][j]){
                    dp[k][i][j] = dp[k-1][i][j];
                    make[k][i][j] = true;
                }
                
                // 이전의 것에 자기 자신을 얹으므로 자기 자신은 한번 밖에 사용되지 않음이 보장 된다.
                if(red<=i && blue<=j && make[k-1][i-red][j-blue]){
                    make[k][i][j] = true;
                    dp[k][i][j] = max(dp[k][i][j],dp[k-1][i-red][j-blue]+danger);
                }
            }
        }
    }
    
    vector<tuple<ll,ll> > ans;
    
    for(ll i=1;i<=N;i++){
        ll a,b; cin>>a>>b;
        ans.push_back({dp[M][a][b],i});
    }
    sort(ans.begin(),ans.end());
    for(ll i=0;i<N;i++){
        cout<<get<1>(ans[i])<<' '<<get<0>(ans[i])<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}


