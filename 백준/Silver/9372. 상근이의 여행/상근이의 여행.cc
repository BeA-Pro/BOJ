#include <iostream>

using namespace std;


int main(){
  //freopen("input.txt","r",stdin);
  int t,n,m;
  cin>>t;
  while(t--){
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
      cin>>a>>b;
    }
    cout<<n-1<<'\n';
  }
  return 0;
}