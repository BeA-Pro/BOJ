#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1]<b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end(), cmp);
    // for(int i=0; i<targets.size();i++){
    //     cout<<targets[i][0]<<' '<<targets[i][1]<<'\n';
    // }
    int cur = targets[0][1];
    for(int i=1;i<targets.size();i++){
        if(cur<=targets[i][0]){
            cur = targets[i][1];
            answer++;
        }
    }
    return answer;
}