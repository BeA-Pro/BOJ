#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string,int> m;

int solution(vector<vector<string>> clothes) {
    for(int i=0;i<clothes.size();i++){
        m[clothes[i][1]]++;
    }
    int answer = 1;
    for(auto iter=m.begin(); iter!=m.end();++iter){
        answer*=(iter->second+1);
    }
    
    return answer-1;
}