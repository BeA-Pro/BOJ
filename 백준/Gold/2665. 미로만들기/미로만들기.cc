#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
int visit[50][50];
vector<string> arr;
int N;


struct Info{
  int cnt, y, x;
  bool operator<(const Info& other) const {
    return cnt > other.cnt;
  }
};

priority_queue<Info> pq;

Info make_info(int cnt, int y , int x){
  Info temp;
  temp.cnt = cnt, temp.y = y, temp.x = x;
  return temp;
}


int cal(int i,int j){
  pq.push(make_info(0,i,j));
  visit[i][j] = 0;

  while(!pq.empty()){
    Info cur = pq.top(); pq.pop();
    
    if(cur.cnt > visit[cur.y][cur.x]) continue;
    if(cur.x == N -1 && cur.y == N-1) break;
    
    
    for(int i=0;i<4;i++){
      int ny = dy[i] + cur.y, nx = dx[i] + cur.x;
      if(0 <= ny && ny < N && 0 <= nx && nx < N){
        int next = cur.cnt;
        if(arr[ny][nx] == '0') next++;
        if(next < visit[ny][nx]){
          visit[ny][nx] = next;
          pq.push(make_info(next,ny,nx));
        }
      }
    }
  }
  // cout<<'\n';
  // for(int i=0;i<N;i++){
  //   for(int j=0;j<N;j++){
  //     cout<<visit[i][j]<<' ';
  //   }
  //   cout<<'\n';
  // }

  return visit[N-1][N-1];
}

int main(){
  fill(&visit[0][0], &visit[49][50], INT_MAX);
  cin>>N;
  arr.resize(N);

  for(int i=0;i<N;i++) cin>>arr[i];

  cout<<cal(0,0);


  return 0;
}