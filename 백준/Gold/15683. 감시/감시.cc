#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// 0 동, 1 남, 2 서, 3 북

int N, M;
int arr[8][8];
vector<pair<int,int> > v;
int ans = 0;

void add(int y, int x, int dir){
  if(dir == 0){ // 동
    while( ++x < M && arr[y][x] != 6 ) if(arr[y][x] <= 0 ) arr[y][x]--;
  }else if(dir == 1){ // 남
    while( ++y < N && arr[y][x] != 6) if(arr[y][x] <=0 ) arr[y][x]--;
  }else if(dir == 2){ // 서
    while( 0 <= --x && arr[y][x] != 6 ) if(arr[y][x] <= 0 ) arr[y][x]--;
  }else { // 북
    while( 0 <= --y && arr[y][x] != 6 ) if(arr[y][x] <= 0) arr[y][x]--;
  }

}

void era(int y, int x,int dir){
  if(dir == 0){ // 동
    while( ++x < M && arr[y][x] != 6 ) if(arr[y][x] < 0 ) arr[y][x]++;
  }else if(dir == 1){ // 남
    while( ++y < N && arr[y][x] != 6) if(arr[y][x] < 0 ) arr[y][x]++;
  }else if(dir == 2){ // 서
    while( 0 <= --x && arr[y][x] != 6 ) if(arr[y][x] < 0 ) arr[y][x]++;
  }else { // 북
    while( 0 <= --y && arr[y][x] != 6 ) if(arr[y][x] < 0) arr[y][x]++;
  }
}

void cal(int index){
  if(index == v.size()){
    int cnt = 0;
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(!arr[i][j]) cnt++;
      }
    }

    ans = min(ans,cnt);
    return;
  }

  int y = v[index].first, x = v[index].second;

  if(arr[y][x]==1){
    for(int i=0; i<4;i++){
      add(y,x,i);
      cal(index+1);
      era(y,x,i);
    }
  }else if(arr[y][x] == 2){
    for(int i = 0; i<2;i++){
      add(y,x,i);
      add(y,x,i+2);
      cal(index+1);
      era(y,x,i);
      era(y,x,i+2);
    }
  }else if(arr[y][x] == 3){
    for(int i=0; i<4;i++){
      add(y,x,i);
      add(y,x,(i+1)%4);
      cal(index+1);
      era(y,x,i);
      era(y,x,(i+1)%4);
    }
  }else if(arr[y][x] == 4){
    for(int i=0; i<4;i++){
      add(y,x,i);
      add(y,x,(i+1)%4);
      add(y,x,(i+2)%4);
      cal(index+1);
      era(y,x,i);
      era(y,x,(i+1)%4);
      era(y,x,(i+2)%4);
    }
  }
  else{
    for(int i=0;i<4;i++) add(y,x,i);
    cal(index+1);
    for(int i=0;i<4;i++) era(y,x,i);
  }

}

int main(){
  cin>>N>>M;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>arr[i][j];
      if(1<=arr[i][j] && arr[i][j]<=5) v.push_back(make_pair(i,j));
      if(!arr[i][j]) ans++;
    }
  }

  cal(0);

  // cout<<'\n';
  //     for(int i=0;i<N;i++){
  //       for(int j=0;j<M;j++){
  //         cout<<setw(2)<<arr[i][j]<<' ';
  //       }
  //       cout<<'\n';
  //     }

  cout<<ans;

  return 0;
}