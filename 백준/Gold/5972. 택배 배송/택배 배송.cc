#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Info{
  int to, cost;
};

struct cmp{
  bool operator()(Info a, Info b){
    return a.cost > b.cost;
  }
};

int N, M;
vector<Info> info[50001];
int visit[50001];

priority_queue<Info, vector<Info>, cmp> pq;

Info make_info(int to, int cost){
  Info temp;
  temp.to = to, temp.cost = cost;
  return temp;
}

int cal(int i){
  pq.push(make_info(i,0));
  visit[i] = 0;

  while(!pq.empty()){
    Info cur = pq.top(); pq.pop();
    for(int i=0;i<info[cur.to].size();i++){
      Info next = info[cur.to][i];
      int next_cost = cur.cost + next.cost;
      if(next_cost < visit[next.to]){
        visit[next.to] = next_cost;
        pq.push(make_info(next.to, next_cost));
      }
    }
  }
  return visit[N];
}

int main(){
  cin>>N>>M;
  fill(&visit[0],&visit[N+1], INT_MAX);
  for(int i=0;i<M;i++){
    int a, b, c;
    cin>>a>>b>>c;
    info[a].push_back(make_info(b,c));
    info[b].push_back(make_info(a,c));
  }

  cout<<cal(1);

  return 0;
}