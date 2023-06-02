#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define ll long long
using namespace std;
int n;
bool check[9];
int arr[50][9];
int ans = 0;
vector<int> v;

int base[5];

void cal_score(){
  int inning = 0;
  int idx = 0;
  int out = 0;
  int score = 0;
  int num;
  int res;
  for(int i=0;i<5;i++) base[i] = 0;
  while(inning!=n){

    num = v[idx];
    res = arr[inning][num];

    if(!res) out++;
    else{
      for(int i=3;i>=1;i--){
        base[min(4,i+res)]+=base[i];
        base[i] = 0;
      }
      base[res]++;
    }

    if(out == 3){
      out = 0;
      //score 갱신
      score+=base[4];
      //이닝을 비운다
      for(int i=0;i<5;i++) base[i] = 0;
      inning++;
    }
    //다음 타자
    idx = (idx+1)%9;
  }

  ans = max(ans,score);
}

void cal(int cnt){
  if(cnt == 9){
    if(v[3]==0) cal_score();
    return;
  }
  for(int i=0;i<9;i++){
    if(!check[i]){
      check[i] = true;
      v.push_back(i);
      cal(cnt+1);
      check[i] = false;
      v.pop_back();
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<9;j++){
      cin>>arr[i][j];
    }
  }
  cal(0);
  cout<<ans;
  return 0;
}