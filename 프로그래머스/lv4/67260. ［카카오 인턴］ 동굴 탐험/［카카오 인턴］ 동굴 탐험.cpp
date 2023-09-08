#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> v[200010];
int f[200010];
int s[200010];
bool wait[200010];
bool visit[200010];
queue<int> q;


bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    
    for(int i=0;i<path.size();i++){
        v[path[i][0]].push_back(path[i][1]);
        v[path[i][1]].push_back(path[i][0]);
    }
    for(int i=0;i<n;i++){
        f[i] = -1;
        s[i] = -1;
    }
    
    for(int i=0;i<order.size();i++){
        f[order[i][0]] = order[i][1];
        s[order[i][1]] = order[i][0];
    }
                                    
    
    q.push(0);
    int cnt = 0;
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        visit[cur] = true;
        
        if(s[cur]!= -1 && !visit[s[cur]]) continue;
        
        cnt++;
        if(f[cur]!= -1 && visit[f[cur]]) q.push(f[cur]);
         
        for(int i=0; i<v[cur].size();i++){
            int next = v[cur][i];
            if(!visit[next]) q.push(next);
        }
    }
    
    // cout<<cnt;
    return cnt==n;
}