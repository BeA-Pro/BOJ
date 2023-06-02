#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define ll long long
using namespace std;
int n,tape;
vector<int> v;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  cin>>n>>tape;
  v.resize(n);
  for(int i=0;i<n;i++) cin>>v[i];
  int cnt = 1;
  int tmp = tape;
  int need;
  sort(v.begin(),v.end());
  for(int i = n-1;i>=1;i--){
    need = v[i] - v[i-1];
    if(tmp-need>=1) tmp-=need;
    else{
      cnt++;
      tmp = tape;
    }
  }

  cout<<cnt;
  return 0;
}