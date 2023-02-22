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
typedef struct _dice{
    int num[6];
    int cur_y,cur_x;
}Dice;

int N,M,K;
int info[20][20];
Dice D;

void swap_dice(int a,int b,int c,int d){
    int tmp = D.num[a];
    D.num[a] = D.num[b];
    D.num[b] = D.num[c];
    D.num[c] = D.num[d];
    D.num[d] = tmp;
}

void move_E(){
    if(D.cur_y+1==M) return;
    D.cur_y+=1;
    swap_dice(0,3,5,2);
    if(info[D.cur_x][D.cur_y]==0) info[D.cur_x][D.cur_y]=D.num[5];
    else {
        D.num[5] = info[D.cur_x][D.cur_y];
        info[D.cur_x][D.cur_y]=0;
    }
    cout<<D.num[0]<<'\n';
}

void move_W(){
    if(D.cur_y-1<0) return;
    D.cur_y-=1;
    swap_dice(0,2,5,3);
    if(info[D.cur_x][D.cur_y]==0) info[D.cur_x][D.cur_y]=D.num[5];
    else {
        D.num[5] = info[D.cur_x][D.cur_y];
        info[D.cur_x][D.cur_y]=0;
    }
    cout<<D.num[0]<<'\n';
}

void move_N(){
    if(D.cur_x-1<0) return;
    D.cur_x-=1;
    swap_dice(0,4,5,1);
    if(info[D.cur_x][D.cur_y]==0) info[D.cur_x][D.cur_y]=D.num[5];
    else {
        D.num[5] = info[D.cur_x][D.cur_y];
        info[D.cur_x][D.cur_y]=0;
    }
    
    cout<<D.num[0]<<'\n';
}

void move_S(){
    if(D.cur_x+1==N) return;
    D.cur_x+=1;
    swap_dice(0,1,5,4);
    if(info[D.cur_x][D.cur_y]==0) info[D.cur_x][D.cur_y]=D.num[5];
    else{
        D.num[5] = info[D.cur_x][D.cur_y];
        info[D.cur_x][D.cur_y]=0;
    }
    
    cout<<D.num[0]<<'\n';
}

void input() {
    cin>>N>>M>>D.cur_x>>D.cur_y>>K;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>info[i][j];
}

void solution() {
    for(int i=0;i<6;i++) D.num[i]=0;
    int query;
    for(int i=0;i<K;i++){
        cin>>query;
        switch(query){
            case 1:
                move_E();
                break;
            case 2:
                move_W();
                break;
            case 3:
                move_N();
                break;
            case 4:
                move_S();
                break;
        }
    }

}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
