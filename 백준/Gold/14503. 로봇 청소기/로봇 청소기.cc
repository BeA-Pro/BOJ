#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

enum{ north, east, south, west };
int dy [] = {-1,1,0,0};
int dx [] = {0,0,1,-1};
int n,m,y,x,dir;
vector<vector<int> > v;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);

  cin>>n>>m;
  cin>> y >>x>>dir;
  for(int i=0;i<n;i++){
    vector<int> tmp(m);
    for(int j=0;j<m;j++){
      cin>>tmp[j];
    }
    v.push_back(tmp);
  }

  
  bool flag = false;
  int cnt = 0;
  while(1){
    // cout<<y<<' '<<x;
    flag = false;
    if(!v[y][x]){
      v[y][x] = -1;
      cnt+=1;
    }


    for(int i=0;i<4;i++){
      int ny = y+dy[i], nx = x+dx[i];
      // 0<=ny && ny < n && 0<=nx && nx < m && 
      if(v[ny][nx]==0) flag = true;
    }

    if(!flag){
      if(dir == north){
        if(v[y+1][x]!=1) y+=1;
        else break;
      }
      else if(dir == east){
        if(v[y][x-1]!=1) x-=1;
        else break;
      }
      else if(dir == south){
        if(v[y-1][x]!=1) y-=1;
        else break;
      }
      else if(dir == west){
        if(v[y][x+1]!=1) x+=1;
        else break;
      }
    }else{
      dir = dir - 1 < 0 ? 3 : dir - 1;
      if(dir == north && !v[y-1][x]) y-=1;
      else if(dir == east && !v[y][x+1]) x+=1;
      else if(dir == south && !v[y+1][x]) y+=1;
      else if(dir == west && !v[y][x-1]) x-=1;
    }
  }
  cout<<cnt;

  return 0;
}