#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define ll long long
using namespace std;

int n;
vector<int> v;
vector<int> dp;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);

  cin>>n;
  v.resize(n);
  dp.resize(n);

  for(int i=0;i<n;i++) cin>>v[i];
  int ans;
  ans = dp[0] = v[0];

  for(int i=1;i<n;i++){
    dp[i] = max(dp[i-1]+v[i], v[i]);
    ans = max(ans,dp[i]);
  }

  cout<<ans;

  return 0;
}