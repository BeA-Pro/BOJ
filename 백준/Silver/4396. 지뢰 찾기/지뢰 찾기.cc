#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n;

char arr1[10][10];
char arr2[10][10];
int ans[10][10];
bool check[10][10];
int dy[] = {-1,1,0,0,-1,-1,1,1}, dx[] = {0,0,-1,1,-1,1,-1,1};
bool flag = false;

void bfs(int s_y,int s_x){
  queue<pair<int,int > > q;
  q.push(make_pair(s_y,s_x));
  check[s_y][s_x]=true;

  while(!q.empty()){
    int y = q.front().first, x = q.front().second;
    q.pop();
    int cnt = 0;
    if(arr1[y][x]=='*') flag = true;
    for(int i=0;i<8;i++){
      int ny = y + dy[i], nx = x + dx[i];
      if(0<= ny && ny < n && 0<=nx && nx < n){
        if(arr2[ny][nx]=='x'  && !check[ny][nx] ){
          q.push(make_pair(ny,nx));
          check[ny][nx] = true;
        }
        if(arr1[ny][nx] == '*') cnt++;
      } 
    }
    ans[y][x] = cnt;
  }

}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>arr1[i][j];
      ans[i][j] = -1;
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>arr2[i][j];
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(arr2[i][j]=='x' and !check[i][j]) bfs(i,j);
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(arr1[i][j] == '*'){
          if(flag) cout<<'*';
          else{
            if(ans[i][j]<0) cout<<'.';
            else cout<<ans[i][j];
          }
      }else{
        if(ans[i][j]<0) cout<<'.';
        else cout<<ans[i][j];
      }
    }
    cout<<'\n';
  }


  return 0;
}