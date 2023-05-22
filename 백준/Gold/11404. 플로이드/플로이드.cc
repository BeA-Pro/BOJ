#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>
#define ll long long
using namespace std;

int cost[101][101];
int n,m,a,b,c;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  
  for(int i=0;i<101;i++){
    for(int j=0;j<101;j++){
      if(i==j) cost[i][j] = 0;
      else cost[i][j] = INT_MAX;
    }
  }

  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>a>>b>>c;
    cost[a][b] = min(cost[a][b],c);
  }

  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(cost[i][k] != INT_MAX && cost[k][j]!= INT_MAX){
          cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
        }
      }
    }
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(cost[i][j] == INT_MAX) cout<<0<<' ';
      else cout<<cost[i][j]<<' ';
    }
    cout<<'\n';
  }

  return 0;
}