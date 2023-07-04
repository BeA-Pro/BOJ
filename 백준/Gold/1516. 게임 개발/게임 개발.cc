#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int N;
vector<int> v[500];
vector<int> cost;
vector<int> ttime;
vector<int> in;
queue<int> q;


int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);

  cin>>N;
  cost.resize(N);
  ttime.resize(N);
  in.resize(N);
  int a;

  for(int i=0;i<N;i++){
    cin>>cost[i];
    while(1){
      cin>>a;
      if(a==-1) break;
      v[a-1].push_back(i);
      in[i]++;
    }
  }



  for(int i=0;i<N;i++){
    // cout<<in[i]<<'\n';
    if(!in[i]) q.push(i);
  }


  while(!q.empty()){
    int cur = q.front(); q.pop();
    ttime[cur]+=cost[cur];
    // cout<<"cur "<<cur<<'\n';
    for(int i=0;i<v[cur].size();i++){
      // cout<<v[cur][i]<<'\n';
      if(--in[v[cur][i]]==0) q.push(v[cur][i]);
      ttime[v[cur][i]]=max(ttime[cur], ttime[v[cur][i]]);
    }
  }

  for(int i=0;i<N;i++)
    cout<<ttime[i]<<'\n';

  return 0;
}