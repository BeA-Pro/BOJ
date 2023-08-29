#include <iostream>

using namespace std;

int N, M;
int arr[50][50];

int cal(int cur, int y, int x){
  int res = 1;
  int i = y, j = x;
  int cnt = 1;
  while(++i<N && ++j<M){
    cnt++;
    if(cur==arr[i][x] && cur==arr[y][j] && cur==arr[i][j]) res = cnt;
  }
  return res;
}

int main(){
  cin>>N>>M;
  char a;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>a;
      arr[i][j] = a - '0';
    }
  }
  int ans = 0;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      int b = cal(arr[i][j],i,j);
      ans = max(ans, b*b);
    }
  }
  cout<<ans;
  return 0;
}