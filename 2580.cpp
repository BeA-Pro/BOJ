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

using namespace std;
int sudo[9][9];

vector<pair<int,int> > pos;
bool flag = false;

void input() {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>sudo[i][j];
            if(sudo[i][j]==0) pos.push_back({i,j});
        }
    }
}

void cal(int idx){
    //cout<<idx<<'\n';
    if(flag) return;
    if(idx == pos.size()){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<sudo[i][j]<<' ';
            }
            cout<<'\n';
        }
        exit(0);
        return;
    }
    
    bool possible[10]={false,};
    int y = pos[idx].first, x = pos[idx].second;

    // y
    for(int i=0;i<y;i++) possible[sudo[i][x]] = true;
    for(int i=y;i<9;i++) possible[sudo[i][x]] = true;
    
    // x
    for(int i=0;i<x;i++) possible[sudo[y][i]] = true;
    for(int i=x;i<9;i++) possible[sudo[y][i]] = true;
    
    int s_x,e_x,s_y,e_y;

    if(x<3){
        s_x = 0;
        e_x = 3;
    }else if(x<6){
        s_x=3;
        e_x=6;
    }else{
        s_x = 6;
        e_x = 9;
    }

    if(y<3){
        s_y = 0;
        e_y = 3;
    }else if(y<6){
        s_y=3;
        e_y=6;
    }else{
        s_y = 6;
        e_y = 9;
    }

    for(int i=s_y;i<e_y;i++)
        for(int j=s_x;j<e_x;j++) possible[sudo[i][j]] = true;


    for(int i=1;i<10;i++){
        if(!possible[i]){
            sudo[y][x] = i;
            cal(idx+1);
            sudo[y][x] = 0;
        }
    }

}


void solution() {
    //cout<<pos.size()<<'\n';
    cal(0);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
