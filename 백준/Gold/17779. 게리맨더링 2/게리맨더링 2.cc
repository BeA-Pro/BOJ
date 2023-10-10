#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dx[] = {-1,1,0,0}, dy[] = {0,0,1,-1};

int arr[21][21];
bool visit[21][21];
bool dp[21][21];
int N;
int ans = 1000000;

struct pos{
  int x,y;
};
// 첫번째 x+d1, y-d1
// 두번째 x+d1+d2, y-d1+d2
// 세번째 x+d2, y+d2
void cal(int x,int y,int d1,int d2){
  if( !(1<=x+d1 && x+d1<=N && 1<=y-d1 && y-d1<=N)) return;
  if( !(1<=x+d1+d2 && x+d1+d2<=N && 1<=y-d1+d2 && y-d1+d2<=N)) return;
  if( !(1<=x+d2 && x+d2<=N && 1<=y+d2 && y+d2<=N)) return;

  
  bool check[21][21];
  fill(&check[0][0],&check[20][21],false);

  queue<pos> q;
  

  int temp = d1;
  while(temp--){
    check[x][y]=true;
    // if(temp!=1){
    //   pos a = {x+1,y};
    //   check[x+1][y] = true;
    //   q.push(a);
    // }
    pos a = {x+1,y};
    check[x+1][y] = true;
    q.push(a);
    x++,y--;
  }
  temp = d2;
  while(temp--){
    check[x][y]=true;
    if(!check[x][y+1]){
      pos a = {x,y+1};
      check[x][y+1] = true;
      q.push(a);
    }
    x++,y++;
  }
  temp = d1;
  while(temp--){
    check[x][y]=true;
    if(!check[x-1][y]){
      pos a = {x-1,y};
      check[x-1][y] = true;
      q.push(a);
    }
    x--,y++;
  }
  temp = d2;
  while(temp--){
    check[x][y]=true;
    if(!check[x][y-1]){
      pos a = {x,y-1};
      check[x][y-1] = true;
      q.push(a);
    }
    x--,y--;
  }
  
  
  

  while(!q.empty()){
    pos cur = q.front(); q.pop();
    for(int i=0;i<4;i++){
      int nx = cur.x + dx[i], ny = cur.y + dy[i];
      if(!check[nx][ny]){
        check[nx][ny] = true;
        pos temp = {nx,ny};
        q.push(temp);
      }
    }
  }

  // cout<<'\n';
  // for(int i=1;i<=N;i++){
  //   for(int j=1;j<=N;j++){
  //     cout<<check[i][j]<<' ';
  //   }
  //   cout<<'\n';
  // }

  int sum[5];
  for(int i=0;i<5;i++) sum[i] = 0;

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(check[i][j]) sum[0]+=arr[i][j];
      else{
        if(1<=i && i<x+d1 && 1<=j && j<=y) sum[1]+=arr[i][j];
        else if(1<=i && i<=x+d2 && y<j && j<=N) sum[2]+=arr[i][j];
        else if(x+d1<=i && i<=N && 1<=j && j<y-d1+d2) sum[3]+=arr[i][j];
        else sum[4]+=arr[i][j];
      }
    }
  }
  int big = sum[0], small=sum[0];
  for(int i=1;i<5;i++){
    big = max(big,sum[i]);
    small = min(small,sum[i]);
  }
  // cout<<big<<' '<<small<<'\n';

  ans = min(ans,big-small);
  
  if(!dp[d1+1][d2]){
    dp[d1+1][d2] = true;
    cal(x,y,d1+1,d2);
  }
  if(!dp[d1][d2+1]){
    dp[d1][d2+1] = true;
    cal(x,y,d1,d2+1);
  }
}

int main(){
  cin>>N;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin>>arr[i][j];
    }
  }

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      fill(&dp[0][0],&dp[20][21],false);
      dp[1][1]=true;
      cal(i,j,1,1);
    }
  }

  cout<<ans;

  return 0;
}