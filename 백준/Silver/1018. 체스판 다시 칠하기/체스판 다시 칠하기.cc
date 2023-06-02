#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define ll long long
using namespace std;
int n,m;
char chess[50][50];
char B_start[8][8] = { {'B','W','B','W','B','W','B','W'},
                      {'W','B','W','B','W','B','W','B'},
                      {'B','W','B','W','B','W','B','W'},
                      {'W','B','W','B','W','B','W','B'},
                      {'B','W','B','W','B','W','B','W'},
                      {'W','B','W','B','W','B','W','B'},
                      {'B','W','B','W','B','W','B','W'},
                      {'W','B','W','B','W','B','W','B'}
                    };

char W_start[8][8] = { {'W','B','W','B','W','B','W','B'},
                      {'B','W','B','W','B','W','B','W'},
                      {'W','B','W','B','W','B','W','B'},
                      {'B','W','B','W','B','W','B','W'},
                      {'W','B','W','B','W','B','W','B'},
                      {'B','W','B','W','B','W','B','W'},
                      {'W','B','W','B','W','B','W','B'},
                      {'B','W','B','W','B','W','B','W'}
                    };

int check_B(int y,int x){
  int cnt = 0;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(chess[y+i][x+j]!=B_start[i][j]) cnt++;
    }
  }
  return cnt;
}

int check_W(int y,int x){
  int cnt = 0;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(chess[y+i][x+j]!=W_start[i][j]) cnt++;
    }
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>chess[i][j];
    }
  }
  // cout<<"B start"<<'\n';
  // print_chess();
  int ans = 64;
  for(int i=0;i<=n-8;i++){
    for(int j=0;j<=m-8;j++){
      ans = min(ans,check_B(i,j));
      ans = min(ans,check_W(i,j));
    }
  }
  cout<<ans;
  return 0;
}