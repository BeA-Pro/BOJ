#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};

bool visit[100][100];
int s_y,s_x,la_y,la_x,d_y,d_x;

int N, M;

int bfs(int sy, int sx, char c, vector<string> maps){
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(sy,sx));
    visit[sy][sx] = true;
    
    while(!q.empty()){
        int size = q.size();
        cnt++;
        
        while(size--){
            int y = q.front().first, x = q.front().second; q.pop();
            for(int i=0;i<4;i++){
                int ny = y + dy[i], nx = x + dx[i];
                if(0<= ny && ny < N && 0 <= nx && nx < M && maps[ny][nx]!='X' && !visit[ny][nx]){
                    if(maps[ny][nx]==c) return cnt;
                    
                    visit[ny][nx] = true;
                    q.push(make_pair(ny,nx));
                }
            }
        }
        
    }
    
    return 0;
}

int solution(vector<string> maps) {
    int answer = 0;
    int cnt = 0;
    N = maps.size();
    M = maps[0].size();
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            if(maps[i][j]=='S'){
                s_y = i, s_x = j;
            }else if(maps[i][j]=='E'){
                d_y = i, d_x = j;
            }else if(maps[i][j]=='L'){
                la_y = i, la_x = j;
            }
        }
    }
    
    fill(&visit[0][0], &visit[99][100], false);
    cnt=bfs(s_y,s_x,'L',maps);
    if(!cnt) return -1;
    answer+=cnt;
    
    fill(&visit[0][0], &visit[99][100], false);
    cnt = bfs(la_y,la_x,'E',maps);
    if(!cnt) return -1;
    answer+=cnt;
    
    return answer;
}