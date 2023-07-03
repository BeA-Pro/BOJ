#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define ll long long
using namespace std;

vector<ll> v;
int n, m;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  cin>>n>>m;
  v.resize(n);
  ll left = 0, right = 0;
  for(int i=0;i<n;i++){
    cin>>v[i];
    right+=v[i];
    left = left > v[i] ? left : v[i];
  }
  ll ans = right;
  while(left<=right){
    ll cnt = 0, mid = (left+right)/2;
    ll sum = 0;
    for(int i=0;i<n;i++){
      if(sum + v[i] > mid){
        cnt++;
        sum = 0;
      }
      sum += v[i];
    }
    if(sum != 0 ) cnt++;
    
    // cout<<mid<<' '<<cnt<<' '<<m<<'\n';
    if(cnt <= m){
      // ans = ans < mid ? ans : mid;
      right = mid - 1;
    }
    else left = mid + 1;
  }
  cout << left;

  return 0;
}