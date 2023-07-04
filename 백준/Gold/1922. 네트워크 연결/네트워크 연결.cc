#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define ll long long
using namespace std;

struct info{
  int cost;
  int a;
  int b;
};

bool cmp(struct info a, struct info b){
    return a.cost<b.cost;
}

int n,m;
vector<int> parent;
vector<struct info> info;

int find_parent(int a){
  if(a==parent[a]) return a;
  return parent[a] = find_parent(parent[a]);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);

  cin>>n>>m;
  
  parent.resize(n+1);
  info.resize(m);
  int a,b,c;

  for(int i=0;i<=n;i++) parent[i] = i;

  for(int i=0;i<m;i++)
    cin>>info[i].a>>info[i].b>>info[i].cost;

  sort(info.begin(),info.end(),cmp);
  
  int total = 0;
  for(int i=0;i<m;i++){
    a = info[i].a, b = info[i].b;
    int p_a = find_parent(a), p_b = find_parent(b);
    
    if(p_a!=p_b){
      parent[p_b] = p_a;
      total+=info[i].cost;
    }
  }

  cout<<total;
  return 0;
}