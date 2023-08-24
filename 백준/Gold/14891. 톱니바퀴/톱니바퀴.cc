#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
#define LEFT 6
#define RIGHT 2
#define TOP 0
using namespace std;

int T;
string a[4];
int num, ro;
int ro_info[4];

// 1 : 시계방향, -1 : 반시계방향
void rotate(){
  char c;
  for(int i=0;i<4;i++){
    if(ro_info[i] == 1){ //시계방향
      c = a[i].back();
      a[i].pop_back();
      a[i] = c + a[i]; // 문자열 앞에 c를 추가
    }else if(ro_info[i] == -1){ //반시계방향
      c = a[i][0];
      a[i].erase(a[i].begin());
      a[i] = a[i] + c; // 문자열 뒤에 c를 추가
    }
  }
}

void cal(int index, int r, int dir){
  ro_info[index]=r;
  //왼쪽 전파
  if(index!=0 && dir == -1){
    if(r == 0 || a[index-1][RIGHT]==a[index][LEFT]){
      cal(index-1,0,-1);
    }
    else{
      cal(index-1,-r,-1);
    }
  }else if(index!=3 && dir == 1){
    if(r == 0 || a[index+1][LEFT]==a[index][RIGHT]){
      cal(index+1,0,1);
    }
    else{
      cal(index+1,-r,1);
    }
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  for(int i=0;i<4;i++) cin>>a[i];
  cin>>T;
  while(T--){
    cin>>num>>ro;
    num--;

    if(num!=0){
      cal(num,ro, -1);
    }
    if(num!=3){
      cal(num,ro,1);
    }
    rotate();
  }
  int ans = 0;
  int score = 1;
  for(int i=0;i<4;i++){
    ans+=(a[i][TOP]-'0')*score;
    score*=2;
  }
  cout<<ans;
}