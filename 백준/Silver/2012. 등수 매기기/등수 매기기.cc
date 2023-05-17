#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  vector<long long> v;
  int n;
  cin>>n;
  v.resize(n);
  for(int i=0;i<n;i++) cin>>v[i];

  sort(v.begin(),v.end());

  long long total = 0;
  for(int i=0;i<n;i++) total+=abs(i+1 - v[i]);
  cout<<total<<'\n';

  return 0;
}