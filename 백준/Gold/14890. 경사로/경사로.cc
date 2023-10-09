#include <iostream>
#include <queue>
using namespace std;

struct info{
  int y,x;
  bool dir, garo; // dir : 0 정방향 반대
};

queue<info> q;
int arr[100][100];

bool g[100][100];
bool s[100][100];
bool garo[100];
bool sero[100];
int n,L;

int main(){
  cin>>n>>L;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>arr[i][j];
    }
  }

  for(int i=0;i<n;i++){ // 가로 체크
    for(int j=0;j<n;j++){
      if(j!=0 && arr[i][j]>arr[i][j-1]){ // 왼쪽 체크
        info temp = {i,j,false, true};
        q.push(temp);
      }
      if(j!=n-1 && arr[i][j]>arr[i][j+1]){ // 오른쪽 체크
        info temp = {i,j,true, true};
        q.push(temp);
      }
    }
  }


  for(int j=0;j<n;j++){ // 세로 체크
    for(int i=0;i<n;i++){
      if(i!=0 && arr[i][j]>arr[i-1][j]){ // 위 체크
        info temp = {i,j,false, false};
        q.push(temp);
      }
      if(i!=n-1 && arr[i][j]>arr[i+1][j]){ // 아래
        // cout<<"i "<<i<<' '<<" j "<<j<<'\n';
        info temp = {i,j,true, false};
        q.push(temp);
      }
    }
  }
  
  int answer = 0;

  while(!q.empty()){
    info cur = q.front(); q.pop();
    // info : y, x, dir, garo
    // cout<<"cur.y "<<cur.y<<" cur.x "<<cur.x<<" cur.dir "<<cur.dir<<" cur.garo "<<cur.garo<<'\n';
    int cnt = 1;
    int v = arr[cur.y][cur.x];

    if(cur.garo){ // 가로
      if(cur.dir){ // 오른쪽
        while(cur.x + cnt <= n && cnt <= L){
          int next = arr[cur.y][cur.x+cnt];
          if(v-1 == next && !g[cur.y][cur.x+cnt]){
            g[cur.y][cur.x+cnt] = true;
            cnt++;
          }else{
            garo[cur.y] = true;
            break;
          }
        }
      }else{ // 왼쪽
        while(cur.x - cnt >= -1 && cnt <= L){
          int next = arr[cur.y][cur.x-cnt];
          if(v-1 == next && !g[cur.y][cur.x-cnt]){
            g[cur.y][cur.x-cnt] = true;
            cnt++;
          }else{
            garo[cur.y] = true;
            break;
          }
        }
      }
    }else{ // 세로
      if(cur.dir){ // 아래
        while(cur.y + cnt <= n && cnt <= L){
          int next = arr[cur.y+cnt][cur.x];
          if(v-1 == next && !s[cur.y+cnt][cur.x]){
            s[cur.y+cnt][cur.x] = true;
            cnt++;
          }else{
            sero[cur.x] = true;
            break;
          }
        }
      }else{ // 위
        while(cur.y - cnt >= -1 && cnt <= L){
          int next = arr[cur.y - cnt][cur.x];
          if(v-1 == next && !s[cur.y - cnt][cur.x]){
            s[cur.y - cnt][cur.x] = true;
            cnt++;
          }else{
            sero[cur.x] = true;
            break;
          }
        }
      }
    }
  }

  for(int i=0;i<n;i++){
    if(!garo[i]){
      // cout<<"가로 "<<i<<'\n';
      answer++;
    }
    if(!sero[i]){
      // cout<<"세로 "<<i<<'\n';
      answer++;
    }
  }
  cout<<answer;
  
  return 0;
}