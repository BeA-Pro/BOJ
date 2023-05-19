#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

string s;
int cnt[10];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  cin>>s;

  for(int i=0;i<s.size();i++){
    int a = s[i] - '0';
    if(a == 9) cnt[6]++;
    else cnt[a]++;
  }

  if(cnt[6]&1) cnt[6] = cnt[6]/2 + 1;
  else cnt[6]/=2; 

  int ans = 0;

  for(int i = 0;i<10;i++) ans = max(ans,cnt[i]);
  cout<<ans;
  return 0;
}