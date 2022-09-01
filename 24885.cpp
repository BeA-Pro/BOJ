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

int N;
ll M,K;
vector<ll> p;
ll ans;

void dfs(int cur_idx, ll money,ll stock_cnt,ll buy_price ,ll loan){
    //cout<<ans<<'\n';
    ll stock_price = p[cur_idx];
    
    if(cur_idx == N - 1){
        if(stock_cnt!=0){
            //일단 팔기
            money+=(stock_price * stock_cnt);
        }
        if(ans < money) ans = money;
        return;
    }
    
    // 그냥 건너 뛰는 경우
    dfs(cur_idx + 1,money,stock_cnt, buy_price ,loan);
    
    
    if(stock_cnt == 0){ // 그날 사는 경우
        
        loan = money * K;
        // 대출을 받아도 못사는 경우 리턴
        if(stock_price > loan + money) return;
        
        stock_cnt = (loan + money) / stock_price;
        money = (loan + money) % stock_price;
        
        dfs(cur_idx + 1,money, stock_cnt, stock_price ,loan);
        return;
    }
    // 그날 파는 경우
    
    // 산 날보다 크지 않으면 팔 이유가 없다.
    if(stock_price <= buy_price) return;
    
    //일단 팔기
    money+=(stock_price * stock_cnt);
    //답 확인
    if(ans < money) ans = money;
    //대출 갚기
    money-=loan;
    // 팔기만하고 건너 뜀
    dfs(cur_idx + 1, money, 0, 0, 0);
    
    //사기
    loan = money * K;
    if(stock_price > loan + money) return;
    stock_cnt = (loan + money) / stock_price;
    money = (loan + money) % stock_price;
    
    //팔고사고 하는 경우
    dfs(cur_idx + 1,money, stock_cnt, stock_price ,loan);
    
}

void input() {
    cin>>N>>M>>K;
    p.resize(N);
    for(int i=0;i<N;i++) cin>>p[i];

}

void init() {
}


void solution() {
    ans = M;
    dfs(0,M,0,0,0);
    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
