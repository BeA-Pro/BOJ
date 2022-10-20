#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <set>

#define p(a, b) make_pair(a, b)
#define SWAP(a, b, type) do { \
    type temp; \
    temp = a;  \
    a = b;     \
    b = temp;  \
} while (0)
#define INF 1000000000
#define endl '\n'
#define ll long long
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4
#define W 0
#define R 1
#define B 2

using namespace std;

typedef struct _info{
    int y;
    int x;
    int direct;
    int st_pos;
}info;

info v[11];
stack<int> MAP[13][13];
int color[13][13];

int N,K;

bool move(int n){
    int d = v[n].direct, y =v[n].y, x=v[n].x;
    
    // 파랑 or 끝인 경우
    if(d==LEFT){
        if(x-1 < 1 || color[y][x-1]==B) v[n].direct=RIGHT;
    }else if(d==RIGHT){
        if(x+1>N || color[y][x+1]==B) v[n].direct=LEFT;
    }else if(d==UP){
        if(y-1 < 1 || color[y-1][x]==B) v[n].direct=DOWN;
    }else{
        if(y+1>N || color[y+1][x]==B) v[n].direct=UP;
    }
    
    // direction 방향으로 이동
    bool flag=false;
    queue<int> q;
    stack<int> s;
    d = v[n].direct;
    int cnt = MAP[y][x].size() - v[n].st_pos;
    
    if(d==LEFT){
        if(!(x-1 < 1 || color[y][x-1]==B)){
            if(color[y][x-1]==R){
                for(int i=0;i<cnt;i++){
                    q.push(MAP[y][x].top());
                    MAP[y][x].pop();
                }
                
                while(!q.empty()){
                    int index = q.front(); q.pop();
                    MAP[y][x-1].push(index);
                    v[index].x=x-1;
                    v[index].st_pos = MAP[y][x-1].size()-1;
                }
            }
            
            if(color[y][x-1]==W){
                for(int i=0;i<cnt;i++){
                    s.push(MAP[y][x].top());
                    MAP[y][x].pop();
                }
                
                while(!s.empty()){
                    int index = s.top(); s.pop();
                    MAP[y][x-1].push(index);
                    v[index].x=x-1;
                    v[index].st_pos = MAP[y][x-1].size()-1;
                }
            }
            if(MAP[y][x-1].size()>=4) flag=true;
            
        }
        
    }
    
    if(d==RIGHT){
        if(!(x+1 > N || color[y][x+1]==B)){
            if(color[y][x+1]==R){
                for(int i=0;i<cnt;i++){
                    q.push(MAP[y][x].top());
                    MAP[y][x].pop();
                }
                
                while(!q.empty()){
                    int index = q.front(); q.pop();
                    MAP[y][x+1].push(index);
                    v[index].x=x+1;
                    v[index].st_pos = MAP[y][x+1].size()-1;
                }
            }
            
            if(color[y][x+1]==W){
                for(int i=0;i<cnt;i++){
                    s.push(MAP[y][x].top());
                    MAP[y][x].pop();
                }
                
                while(!s.empty()){
                    int index = s.top(); s.pop();
                    MAP[y][x+1].push(index);
                    v[index].x=x+1;
                    v[index].st_pos = MAP[y][x+1].size()-1;
                }
            }
            if(MAP[y][x+1].size()>=4) flag=true;
        }
    }
    
    if(d==UP){
        if(!(y-1 < 1 || color[y-1][x]==B)){
            if(color[y-1][x]==R){
                for(int i=0;i<cnt;i++){
                    q.push(MAP[y][x].top());
                    MAP[y][x].pop();
                }
                
                while(!q.empty()){
                    int index = q.front(); q.pop();
                    MAP[y-1][x].push(index);
                    v[index].y=y-1;
                    v[index].st_pos = MAP[y-1][x].size()-1;
                }
            }
            
            if(color[y-1][x]==W){
                for(int i=0;i<cnt;i++){
                    s.push(MAP[y][x].top());
                    MAP[y][x].pop();
                }
                
                while(!s.empty()){
                    int index = s.top(); s.pop();
                    MAP[y-1][x].push(index);
                    v[index].y=y-1;
                    v[index].st_pos = MAP[y-1][x].size()-1;
                }
            }
            if(MAP[y-1][x].size()>=4) flag=true;
        }
        
    }
    
    if(d==DOWN){
        if(!(y+1 > N || color[y+1][x]==B)){
            if(color[y+1][x]==R){
                for(int i=0;i<cnt;i++){
                    q.push(MAP[y][x].top());
                    MAP[y][x].pop();
                }
                
                while(!q.empty()){
                    int index = q.front(); q.pop();
                    MAP[y+1][x].push(index);
                    v[index].y=y+1;
                    v[index].st_pos = MAP[y+1][x].size()-1;
                }
            }
            
            if(color[y+1][x]==W){
                for(int i=0;i<cnt;i++){
                    s.push(MAP[y][x].top());
                    MAP[y][x].pop();
                }
                
                while(!s.empty()){
                    int index = s.top(); s.pop();
                    MAP[y+1][x].push(index);
                    v[index].y=y+1;
                    v[index].st_pos = MAP[y+1][x].size()-1;
                }
            }
            if(MAP[y+1][x].size()>=4) flag=true;
        }
        
    }
    
    return flag;
}

void input() {
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>color[i][j];
        }
    }
    
    for(int i=1;i<=K;i++){
        info tmp;
        int y,x,d;
        tmp.st_pos=0;
        
        cin>>y>>x>>d;
        tmp.y=y;
        tmp.x=x;
        tmp.direct=d;
        v[i]=tmp;
        MAP[y][x].push(i);
    }
    
}

void init() {
}


void solution() {
    int MAX=1000;
    
    for(int k=1;k<=MAX;k++){
        for(int i=1;i<=K;i++){
            if(move(i)){
                cout<<k;
                return;
            }
        }
    }
    
    cout<<-1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
