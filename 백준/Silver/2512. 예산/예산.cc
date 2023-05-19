

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define ll long long
using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  ll maax = 0;
  int n,m;
  cin>>n;
  vector<ll> v(n);

  for(int i=0;i<n;i++){
    cin>>v[i];
    maax = max(maax, v[i]);
  }
  cin>>m;

  ll left = 0, right = maax;

  ll ans = 0;
  ll sum = 0;
  while(left<=right){
    ll mid = (left+right)/2;

    sum = 0;
    
    for(int i=0;i<n;i++) sum+=min(v[i],mid);

    if(sum <= m ){
      ans = mid;
      left = mid + 1;
    }
    else right = mid - 1;
  
  }
  cout<<ans;
  return 0;
}