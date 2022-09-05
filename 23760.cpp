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
#define MAX 100000

using namespace std;

vector<int> seg;
vector<int> c;
vector<int> w;
vector<int> b;
int N,M;

void input() {
}

void init() {
}


int Make_SegmentTree(int Node,int Start, int End){
    if(Start == End) return seg[Node] = c[Start];
    
    int Mid = (Start + End)/2;
    
    return seg[Node] = Make_SegmentTree(Node*2,Start,Mid) + Make_SegmentTree(Node*2 + 1,Mid+1,End);
}

int update(int Node, int Start, int End, int K, int diff){
    seg[Node]--;
    
    if(Start == End){
        if(Start >= diff){ // K번째가 아이들이 원하는 것보다 클 경우
            c[Start]--;
            return Start - diff;
        }
        
        return -1;
    }
    

    int Mid = (Start + End)/2;
    int cnt = seg[Node * 2 + 1];
    
    if(K <= cnt ) return update(Node * 2 + 1, Mid + 1, End, K ,diff);
    return update(Node * 2 , Start, Mid,  K - cnt, diff);
}

void update2(int Node, int Start, int End, int index){
    if(Start > index || End < index) return;
    
    seg[Node]++;
    
    if(Start == End){
        c[Start]++;
        return;
    }
    
    
    int Mid = (Start + End)/2;
    
    if(index <= Mid ) update2(Node * 2, Start, Mid,index);
    else update2(Node * 2 + 1, Mid + 1, End, index);
    
}

void solution() {
    int h = (int)ceil(log2(MAX+1));
    int tree_size = (1<<(h + 1));
    seg.resize(tree_size);
    
    cin>>N>>M;
    
    c.resize(MAX+1);
    w.resize(M);
    b.resize(M);
    
    int cnt;
    
    for(int i=0;i<N;i++){
        cin>>cnt;
        c[cnt]++;
    }
    
    Make_SegmentTree(1,1,MAX);
    
    for(int i=0;i<M;i++) cin>>w[i];
    for(int i=0;i<M;i++) cin>>b[i];

    
    for(int i=0;i<M;i++){
        //w[i] 원하는 선물 개수, b[i] 배려심
        //update b[i]번째를 w[i]만큼 빼라
        if(b[i]>seg[1]){
            cout<<0;
            return;
        }
        int index = update(1,1,MAX,b[i],w[i]);
        
        if( index == -1){
            cout<<0;
            return;
        }else update2(1,1,MAX,index);

    }

    cout<<1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
