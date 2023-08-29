#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int H,W;

int main(){
  cin>>H>>W;
  v.resize(W);
  for(int i=0;i<W;i++){
    cin>>v[i];
  }
  int left = 0, right = W-1;
  int ans = 0;
  while(!v[left] && left < W - 1) left++;
  while(!v[right] && right > 0) right--;

  //l, r 기둥
  int l = v[left], r = v[right];

  while(left<right){
    if(l>r){
      ans += r - v[right];
      if( v[--right] > r ) r = v[right];
    }else{
      ans += l - v[left];
      if( v[++left] > l ) l = v[left];
    }
  } 
  cout<<ans;

  return 0;
}