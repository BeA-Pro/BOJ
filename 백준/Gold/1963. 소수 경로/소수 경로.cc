#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define ll long long
using namespace std;

bool prime[10000];
bool check[10000];
int t,a,b;

int bfs(int s, int e){
  check[s] = true;
  queue<int> q;
  q.push(s);
  int cnt = 0;

  while(!q.empty()){
    int size = q.size();
    while(size--){
      int cur = q.front(); q.pop();

      if(cur == e) return cnt;

      int one = cur % 10;
      int two = (cur % 100 - one) / 10;
      int three = (cur % 1000 - two * 10 - one) / 100;
      int four = (cur - three * 100 - two * 10 - one) / 1000;

      // cout<<"cur "<<cur<<'\n';
      // cout<<four<<three<<two<<one<<'\n';

      for(int i = cur, temp = one + 1; temp < 10; temp++){
        i += 1;
        // cout<<i<<'\n';
        if(i>=1000 && i < 10000 && !prime[i] && !check[i]){
          // cout<<i<<" push to q\n";
          check[i] = true;
          q.push(i);
        }
      }

      for(int i = cur, temp = one - 1; temp >= 0; temp--){
        i -= 1;
        // cout<<i<<'\n';
        if(i>=1000 && i < 10000 && !prime[i] && !check[i]){
          // cout<<i<<" push to q\n";
          check[i] = true;
          q.push(i);
        }
      }

      for(int i = cur, temp = two + 1; temp < 10; temp++){
        i += 10;
         //cout<<i<<'\n';
        if(i>=1000 && i < 10000 && !prime[i] && !check[i]){
          // cout<<i<<" push to q\n";
          check[i] = true;
          q.push(i);
        }
      }

      for(int i = cur, temp = two - 1; temp >= 0; temp--){
        i -= 10;
        // cout<<i<<'\n';
        if(i>=1000 && i < 10000 && !prime[i] && !check[i]){
          // cout<<i<<" push to q\n";
          check[i] = true;
          q.push(i);
        }
      }

      for(int i = cur, temp = three + 1; temp < 10; temp++){
        i += 100;
        // cout<<i<<'\n';
        if(i>=1000 && i < 10000 && !prime[i] && !check[i]){
          // cout<<i<<" push to q\n";
          check[i] = true;
          q.push(i);
        }
      }

      for(int i = cur, temp = three - 1; temp >= 0; temp--){
        i -= 100;
        // cout<<i<<'\n';
        if(i>=1000 && i < 10000 && !prime[i] && !check[i]){
          // cout<<i<<" push to q\n";
          check[i] = true;
          q.push(i);
        }
      }

      for(int i = cur, temp = four + 1; temp < 10; temp++){
        i += 1000;
        // // cout<<i<<'\n';
        if(i>=1000 && i < 10000 && !prime[i] && !check[i]){
          // cout<<i<<" push to q\n";
          check[i] = true;
          q.push(i);
        }
      }

      for(int i = cur, temp = four - 1; temp >= 0; temp--){
        i -= 1000;
        // cout<<i<<'\n';
        if(i>=1000 && i < 10000 && !prime[i] && !check[i]){
          // // cout<<i<<" push to q\n";
          check[i] = true;
          q.push(i);
        }
      }
    }
    cnt++;
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  prime[0] = prime[1] = true;

  for(int i=2;i<10000;i++){
    if(!prime[i]){
      int next = 2*i;
      while(next < 10000){
        prime[next] = true;
        next+=i;
      }
    }
  }

  cin>>t;
  
  while(t--){
    cin>>a>>b;
    fill(&check[0],&check[10000],false);
    // bfs(a,b);
    cout<<bfs(a,b)<<'\n';
  }

  return 0;
}