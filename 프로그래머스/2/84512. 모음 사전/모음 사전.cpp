#include <string>
#include <vector>

using namespace std;

string s = "AEIOU";
int cnt = 0;
int ans = 0;
void dfs(string cur,string word){
    for(int i=0;i<s.size();i++){
        cnt++;
        cur.push_back(s[i]);
        if(cur.size() == word.size()){
            if(cur == word) ans = cnt;
        }
        if(cur.size() !=5) dfs(cur,word);
        cur.pop_back();
    }
}

int solution(string word) {
    int answer = 0;
    string cur = "";
    
    dfs(cur,word);
    return ans;
}