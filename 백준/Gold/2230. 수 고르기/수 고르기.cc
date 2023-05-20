#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define ll long long
using namespace std;
vector<ll> v;

ll n,m;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  cin>>n>>m;
  v.resize(n);

  for(int i=0;i<n;i++) cin>>v[i];

  sort(v.begin(),v.end());

  ll s = 0, e = 0;
  // ll ans_l = v[left], ans_r = v[right];
  ll ans = v[n-1] - v[0];

  // while(left<=right){
  //   if(v[right]-v[left] < m) break;
  //   // if(v[right]-v[left] < ans) ans = v[right]-v[left];
  //   ans = min(ans,v[right]-v[left]);
  //   if(v[right] - v[right-1] < v[left+1] - v[left]) right--;
  //   else left++;
    
  // }

  while(s < n && e < n){
    if(v[e]-v[s]>=m){
      ans = min(v[e]-v[s],ans);
      s++;
    }else e++;
  }
  cout<<ans;
  return 0;
}