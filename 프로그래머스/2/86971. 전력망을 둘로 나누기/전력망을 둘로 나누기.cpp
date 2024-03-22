#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;
vector<int> v[101];
bool visit[101];

int bfs(int s, int ban){
    fill(&visit[0],&visit[101], false);
    visit[ban] = visit[s] = true;
    queue<int> q;
    q.push(s);
    int cnt = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cnt++;
        for(int i=0;i<v[cur].size();i++){
            if(!visit[v[cur][i]]){
                visit[v[cur][i]] = true;
                q.push(v[cur][i]);
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    for(int i=0;i<wires.size();i++){
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }
    for(int i=0;i<wires.size();i++){
        int tmp = bfs(wires[i][0],wires[i][1]);
        // cout<<i<<' '<<tmp<<'\n';
        int diff = abs((n-tmp)-tmp);
        // cout<<diff<<'\n';
        answer=min(answer, diff);
    }
    
    return answer;
}