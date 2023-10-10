#include <iostream>
#include <vector>
#define N 100
using namespace std;

bool arr[101][101];
int dy[] = {0,-1,0,1}, dx[] = {1,0,-1,0};


void dragon(int x,int y,int d, int g){
  vector<int> dir;
  
  
  arr[y][x] = true;

  dir.push_back(d);
  y+=dy[d], x+=dx[d];
  arr[y][x] = true;
  
  while(g--){
    int size = dir.size()-1;
    for(int i=size;i>=0;i--){
      int next = (dir[i]+1)%4;
      y+=dy[next], x+=dx[next];
      arr[y][x] = true;
      dir.push_back(next);
    }
  }
}


int main(){
  int t,x,y,d,g;
  cin>>t;
  while(t--){
    cin>>x>>y>>d>>g;
    dragon(x,y,d,g);
  }

  // for(int i=0;i<10;i++){
  //   for(int j=0;j<10;j++){
  //     cout<<arr[i][j];
  //   }
  //   cout<<'\n';
  // }
  int answer = 0;
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      if(arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1]) answer++;
    }
  }
  cout<<answer;
  return 0;
}