#include <iostream>
#include <string>
using namespace std;

int main(){
  char c;
  string S;
  getline(cin, S);
  int index = 0;

  while(index!=S.size()){
    string s ="";
    if(S[index]=='<'){
      while(S[index]!='>') s.push_back(S[index++]);
      cout<<s<<'>';
      index++;
    }else{
      if(S[index]==' '){
        cout<<' ';
        index++;
      }
      else{
        while(index!=S.size() && S[index]!=' ' && S[index]!='<') s.push_back(S[index++]);

        for(int i=s.size()-1;i>=0;i--) cout<<s[i];
        // cout<<index<<'\n';
        
      }
    }
  }
}