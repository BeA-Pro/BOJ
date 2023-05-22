#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#define ll long long
using namespace std;



int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //freopen("input.txt","r",stdin);
  int t;
  cin>>t;
  string s;
  while(t--){
    cin>>s;
    // cout<<s<<'\n';
    stack<char> first;
    stack<char> second;
    for(int i=0; i<s.size();i++){
      if(s[i] == '<'){
        if(!first.empty())
        {
          second.push(first.top());
          first.pop();
        }
        
        
      }
      else if(s[i]=='>')
      {
        if(!second.empty())
        {
          first.push(second.top());
          second.pop();
        }
        
      }
      else if(s[i]=='-'){
        if(!first.empty()) first.pop();
      }

      else first.push(s[i]);
    }

    while(!first.empty()){
        second.push(first.top());
        first.pop();
      }
      while(!second.empty()){
        cout<<second.top();
        second.pop();
      }
      cout<<'\n';
  }

  return 0;
}