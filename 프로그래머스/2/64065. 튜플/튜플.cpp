#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

bool check[100001];

bool cmp(string a, string b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> cur;
    string temp = "";
    
    for(int i=1;i<s.size()-1;i++){
        if(s[i] == '{') continue;
        
        if(s[i]=='}'){
            cur.push_back(temp);
            temp = "";
            i++;
        }else{
            temp.push_back(s[i]);
        }
    }
    sort(cur.begin(), cur.end(), cmp);
    // for(int i=0;i<cur.size();i++) cout<<cur[i]<<'\n';
    
    for(int i=0;i<cur.size();i++){
        // cout<<cur[i]<<"\n";
        string temp2 = "";
        for(int j=0;j<cur[i].size();j++){
            if(cur[i][j] == ','){
                int num = stoi(temp2);
                // cout<<"num "<<num<<"\n";
                temp2="";
                if(!check[num]){
                    check[num] = true;
                    answer.push_back(num);
                    break;
                }
            }else temp2.push_back(cur[i][j]);
            
            if(j==cur[i].size()-1 && temp2!=""){
                int num = stoi(temp2);
                // cout<<"num "<<num<<"\n";
                temp2="";
                if(!check[num]){
                    check[num] = true;
                    answer.push_back(num);
                    break;
                }
            }
        }
    }
    return answer;
}