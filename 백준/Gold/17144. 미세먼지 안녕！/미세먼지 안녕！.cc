#include <iostream>
#include <queue>
using namespace std;
int Dy[] = {0,-1,0,1}, Dx[] = {1,0,-1,0};
int R, C, T;
int arr[100][100];
int uy = -1,ux=-1,dy=-1,dx=-1;

struct info{
  int y, x, v;
};

void extend(){
  queue<info> q;

  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(arr[i][j]>0){
        int cnt = 0;
        for(int k=0;k<4;k++){
          int ny = Dy[k] + i, nx = Dx[k] + j;
          if(0<=ny && ny<R && 0<=nx && nx<C && arr[ny][nx]!=-1){
            info temp = {ny, nx, arr[i][j]/5};
            q.push(temp);
            cnt++;
          }
        }
        arr[i][j]-=(arr[i][j]/5)*cnt;
      }
    }
  }

  while(!q.empty()){
    info temp = q.front(); q.pop();
    arr[temp.y][temp.x]+=temp.v;
  }
}

void clean(){
  int y=uy, x=ux;
  int ny, nx;
  int dir = 5;
  // int Dy[] = {0,-1,0,1}, Dx[] = {1,0,-1,0}; 오, 위, 왼, 아
  while(y!=0){ //dir 5 -> 1 위
    ny = y+Dy[dir%4], nx = x+Dx[dir%4];
    arr[y][x] = arr[ny][nx];
    y = ny, x = nx;
  }
  dir--; //dir 4 -> 0 오른쪽
  while(x!=C-1){
    ny = y+Dy[dir%4], nx = x+Dx[dir%4];
    arr[y][x] = arr[ny][nx];
    y = ny, x = nx;
  }
  dir--; // dir 3 -> 3 아래
  // cout<<"y "<<y<<" uy "<<uy<<'\n';
  while(y!=uy){
    ny = y+Dy[dir%4], nx = x+Dx[dir%4];
    // cout<<"ny "<<ny<<" nx "<<nx<<'\n';
    arr[y][x] = arr[ny][nx];
    y = ny, x = nx;
  }
  dir--; // dir 2 -> 2 왼쪽 
  while(x!=1){
    ny = y+Dy[dir%4], nx = x+Dx[dir%4];
    arr[y][x] = arr[ny][nx];
    y = ny, x = nx;
  }
  arr[y][x]=0;

  dir = 3;
  // int Dy[] = {0,-1,0,1}, Dx[] = {1,0,-1,0}; 오, 위, 왼, 아
  y = dy, x = dx;
  while(y!=R-1){ //dir 3 -> 3 아래
    ny = y+Dy[dir%4], nx = x+Dx[dir%4];
    arr[y][x] = arr[ny][nx];
    y = ny, x = nx;
  }
  dir++; //dir 4 -> 0 오른쪽
  while(x!=C-1){
    ny = y+Dy[dir%4], nx = x+Dx[dir%4];
    arr[y][x] = arr[ny][nx];
    y = ny, x = nx;
  }
  dir++; // dir 0 -> 1 위
  while(y!=dy){
    ny = y+Dy[dir%4], nx = x+Dx[dir%4];
    arr[y][x] = arr[ny][nx];
    y = ny, x = nx;
  }
  dir++; // dir 2 -> 2 왼쪽 
  while(x!=1){
    ny = y+Dy[dir%4], nx = x+Dx[dir%4];
    arr[y][x] = arr[ny][nx];
    y = ny, x = nx;
  }
  arr[y][x]=0;
  arr[uy][ux] = arr[dy][dx] = -1;

}

int main(){
  cin>>R>>C>>T;

  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cin>>arr[i][j];
      if(arr[i][j]==-1){
        if(uy==-1){
          uy = i;
          ux = j;
        }else{
          dy = i;
          dx = j;
        }
      }
    }
  }

  while(T--){
    extend();
  //   cout<<'\n';
  // for(int i=0;i<R;i++){
  //   for(int j=0;j<C;j++){
  //     cout<<arr[i][j]<<' ';
  //   }
  //   cout<<'\n';
  // }
    clean();
  //   cout<<'\n';
  // for(int i=0;i<R;i++){
  //   for(int j=0;j<C;j++){
  //     cout<<arr[i][j]<<' ';
  //   }
  //   cout<<'\n';
  // }
    
  }
  int answer = 0;
  // cout<<'\n';
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      // cout<<arr[i][j]<<' ';
      if(arr[i][j]>0) answer+=arr[i][j];
    }
    //  cout<<'\n';
  }
  cout<<answer;

  return 0;
}