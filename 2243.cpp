
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
#define MAX 1000000
#define endl '\n'
#define ll long long

using namespace std;

vector<ll> seg;
int arr[MAX+5];

void update(int Node, int Start, int End,int index, int diff){
    if(Start > index || End < index) return;
    seg[Node]+=diff;
    
    if(Start!=End){
        int Mid = (Start + End)/2;
        update(Node * 2, Start, Mid, index, diff);
        update(Node * 2 + 1, Mid + 1, End, index, diff);
    }
}

void input() {
}

void init() {
}

int query(int Node, int Start, int End, int Cnt){
    if(Start == End) return Start;
    int Mid = (Start + End)/2;
    
    if(seg[Node * 2]>=Cnt) return query(Node * 2,Start,Mid,Cnt);
    
    return query(Node * 2 + 1,Mid + 1,End, Cnt - seg[Node * 2]);
}

void solution() {
    int N; cin>>N;
    int command,a,b,pos, diff;
    int Height = (int)ceil(log2(MAX));
    //cout<< (1<<(Height+1));
    int Tree_Size = 1 << (Height + 1);
    seg.resize(Tree_Size);
  
    
    for(int i=0;i<N;i++){
        cin>>command;
        if(command == 2){
            cin>>a>>b;
            arr[a] += b;
            update(1, 1, MAX, a, b);
        }else{
            cin>>a;
            pos = query(1, 1, MAX, a);
            cout<<pos<<'\n';
            arr[pos]--;
            update(1, 1, MAX, pos, -1);
        }
    }
    
    //for(int i=1;i<=3;i++) cout<<arr[i]<<' ';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
