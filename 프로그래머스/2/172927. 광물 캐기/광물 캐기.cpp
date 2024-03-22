#include <string>
#include <vector>
#include <iostream>
using namespace std;

int info[3][3] = {{1,1,1},{5,1,1},{25,5,1}};

int dfs(vector<int> &picks, vector<string> &minerals,int index){
    // cout<<"index "<<index<<'\n';
    int ans = -1;
    for(int i=0;i<3;i++){
        if(picks[i] == 0) continue;
        picks[i]--;
        int tmp = 0;
        int tmp_index = index;
        for(int j=0; j < 5 && tmp_index < minerals.size(); j++, tmp_index++){
            
            int k = 0;
            if(minerals[tmp_index]=="diamond") k = 0;
            else if(minerals[tmp_index] == "iron") k = 1;
            else k = 2;
            tmp+=info[i][k];
        }
        if(tmp_index!=minerals.size()){
            tmp += dfs(picks,minerals,tmp_index);
        }
        
        if(ans == -1) ans = tmp;
        else ans = min(tmp,ans);
        picks[i]++;
    }
    if(ans == -1) return 0;
    return ans;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = dfs(picks,minerals,0);

    
    return answer;
}