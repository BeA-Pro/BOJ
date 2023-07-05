#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define ll long long
using namespace std;

int n, ans;
vector<int> v, dp1, dp2;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  cin>>n;
  v.resize(n);
  dp1.resize(n);
  dp2.resize(n);

  for(int i=0;i<n;i++) cin>>v[i];
  ans = dp1[0] = dp2[0] = v[0];

  for(int i=1;i<n;i++){
    dp1[i] = max(dp1[i-1]+v[i], v[i]);
    dp2[i] = max(dp1[i-1],dp2[i-1] + v[i]);
    ans = max(ans,max(dp1[i],dp2[i]));
  }

  cout<<ans;

  return 0;
}