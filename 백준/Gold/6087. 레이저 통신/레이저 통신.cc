#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int dy[] = {1,-1,0,0}, dx[] = {0,0,1,-1};
vector<string> arr;
int visit[100][100][4];
int N,M;
int sx,sy,ex,ey;

typedef struct info{
  int cnt,y,x,dir;

  
} Info;

bool operator<(Info a, Info b){
    return a.cnt > b.cnt;
}

priority_queue<Info> pq;

Info make_info(int cnt, int y, int x, int dir){
  Info temp;
  temp.cnt = cnt;
  temp.y = y;
  temp.x = x;
  temp.dir = dir;
  return temp;
}

// 0 : 북, 1 : 동, 2 : 남, 3 : 서
int cal(int start_y,int start_x, int end_y, int end_x){
  for(int i=0;i<4;i++){
    visit[start_y][start_x][i] = 1;
    pq.push(make_info(1,start_y,start_x,i));
  }

  while(!pq.empty()){
    Info cur = pq.top(); pq.pop();
    int y = 0,x = 0;
    if(cur.dir == 0) y--;
    else if(cur.dir == 1) x++;
    else if(cur.dir == 2) y++;
    else x--;

    int ny = cur.y + y, nx = cur.x + x;
    if(ny == end_y && nx == end_x) return cur.cnt-1;

    if(0 <= ny && ny < N && 0 <= nx && nx < M && arr[ny][nx]!='*'){
      for(int i=0;i<4;i++){
        int cnt = cur.cnt;
        if(i!=cur.dir) cnt++;

        if(!visit[ny][nx][i] || cnt < visit[ny][nx][i]){
          visit[ny][nx][i] = cnt;
          pq.push(make_info(cnt,ny,nx,i));
        }
      }
    }
  }
  return 0;
}


int main(){
  cin>>M>>N;
  arr.resize(N);
  for(int i=0;i<N;i++) cin>>arr[i];
  sx = sy = ex = ey = -1;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(arr[i][j]=='C'){
        if(sx==-1){
          sy = i;
          sx = j;
        }else{
          ey = i;
          ex = j;
        }
      }
    }
  }

  cout<<cal(sy,sx,ey,ex)<<'\n';
}