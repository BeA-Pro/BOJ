#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct cmp{
  bool operator()(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
  }
};

int n,m,r;
int items[101];
vector<int> v[101];
int cost[101][101];
int dist[101][101];
bool check[101];


int di(int start){
  int ans = 0;
  for(int i=1;i<=n;i++){
    check[i] = false;
    for(int j=1;j<=n;j++){
      dist[i][j] = INT_MAX;
    }
  }

  priority_queue<pair<int,int>, vector<pair<int,int> >, cmp > pq;
  pq.push(make_pair(0,start));

  while(!pq.empty()){
    int cur_dist = pq.top().first, cur_pos = pq.top().second; pq.pop();
    if(check[cur_pos]) continue;
    check[cur_pos] = true;
    ans+=items[cur_pos];

    for(int i=0;i<v[cur_pos].size();i++){
      int next = v[cur_pos][i];
      int next_dist = cur_dist + cost[cur_pos][next];
      if(next_dist > m) continue;
      if(dist[cur_pos][next] > next_dist){
        dist[cur_pos][next] = next_dist;
        pq.push(make_pair(next_dist,next));
      }
    }
  }
  return ans;
}

int main(){
  

  cin>>n>>m>>r;
  for(int i=1;i<=n;i++) cin>>items[i];
  
  for(int i=0;i<r;i++){
    int a, b,c;
    cin>>a>>b>>c;
    v[a].push_back(b);
    v[b].push_back(a);
    cost[a][b] = c;
    cost[b][a] = c;
  }
  int ans = 0;
  for(int i=1;i<=n;i++){
    ans = max(ans,di(i));
  }

  cout<<ans;
  return 0;
}