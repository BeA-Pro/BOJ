#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct{
  int cost;
  int a;
  int b;
} node;

int cost[1001][1001];
int n,m;
int parent[1001];
vector<node> v;
 
bool cmp(node a, node b){
  return a.cost < b.cost;
}

int find_parent(int a){
  if(parent[a] == a) return a;
  return parent[a] = find_parent(parent[a]);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  for(int i=0;i<=1001;i++) parent[i] = i;
  //freopen("input.txt","r",stdin);
  
  cin>>n>>m;
  int a,b;
  int p_a,p_b;

  for(int i=0;i<m;i++){
    cin>>a>>b;
    p_a = find_parent(a);
    p_b = find_parent(b);
    if(p_a!=p_b){
      parent[p_b] = p_a;
    }
  }

  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) cin>>cost[i][j];

  for(int i=2;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      node tmp;
      tmp.a = i;
      tmp.b = j;
      tmp.cost = cost[i][j];
      v.push_back(tmp);
    }
  }

  sort(v.begin(),v.end(),cmp);

  int c;
  int total = 0;
  vector<pair<int, int> > ans;
  for(int i=0;i<v.size();i++){
    a = v[i].a, b = v[i].b, c = v[i].cost;
    p_a = find_parent(a);
    p_b = find_parent(b);
    if(p_a!=p_b){
      parent[p_b] = p_a;
      ans.push_back(make_pair(a,b));
      total+=c;
    }

  }

  cout<<total<<' '<<ans.size()<<'\n';

  for(int i=0;i<ans.size();i++) cout<<ans[i].first<<' '<<ans[i].second<<'\n';
  return 0;
}