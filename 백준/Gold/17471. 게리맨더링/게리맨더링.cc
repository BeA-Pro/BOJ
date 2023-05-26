#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>
#define ll long long
using namespace std;
int n,m,c;
vector<int> v;
vector<int> g[11];
int color[11];
bool check[11];
int ans = INT_MAX;

void bfs(int s){

  queue<int> q;
  check[s] = true;
  q.push(s);
  int col = color[s];

  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(int i=0;i<g[cur].size();i++){
      int nxt = g[cur][i];
      if(col == color[nxt] && !check[nxt]){
        check[nxt] = true;
        q.push(nxt);
      }
    }
  }

}

void cal(int idx,int cnt){
  if(cnt!=0 && cnt!=n){
    
    bool flag0 = false, flag1 = false;
    bool flag2 = false;
    //check 배열 초기화
    for(int j=1;j<=n;j++) check[j] = false;

    for(int i=1;i<=n;i++){
      
      if(!color[i] && !flag0 && !check[i]){
        bfs(i);
        flag0 = true;
      }
      else if(color[i] && !flag1 && !check[i]){
        bfs(i);
        flag1 = true;
      }
      else if(!color[i] && flag0 && !check[i]) flag2=true;
      else if(color[i] && flag1 && !check[i]) flag2=true;
    }
    
    int team0 = 0, team1 = 0;
    for(int i=1;i<=n;i++){
      if(!color[i]) team0+=v[i];
      else team1+=v[i];
    }
    if(!flag2) ans = min(ans,abs(team0-team1));
  }


  if(idx == n+1) return;

  color[idx] = 1;
  cal(idx+1,cnt + 1);
  color[idx] = 0;
  cal(idx+1, cnt);
  // for(int i=idx;i<n;i++){
  //   color[idx] = 1;
  //   cal(idx+1,cnt+1);
  //   color[idx] = 0;
  //   cal(idx+1,cnt);
  // }
}



int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  cin>>n;
  v.resize(n+1);
  for(int i=1;i<=n;i++) cin>>v[i];

  for(int i=1;i<=n;i++){
    cin>>m;
    for(int j=0;j<m;j++){
      cin>>c;
      g[i].push_back(c);
    }
  }

  // for(int i=0;i<n;i++) color[i] = 0;

  cal(1,0);

  if(ans == INT_MAX) cout<<-1;
  else cout<<ans;


  return 0;
}