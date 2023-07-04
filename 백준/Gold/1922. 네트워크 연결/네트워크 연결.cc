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

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

vector<pair<pair<int,int>,int> > v;
int N,M,ans=0;

int parent[1001];

bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.second<b.second;
}

int find_parent(int n){
    if(parent[n]==n) return n;
    else return find_parent(parent[n]);
}

void input(){
    int to,from,cost;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>to>>from>>cost;
        if(to==from) continue;
        v.push_back(make_pair(make_pair(to,from),cost));
    }
    
}

void init() {
    for(int i=0;i<=1000;i++) parent[i]=i;
}


void solution() {
    sort(v.begin(),v.end(),cmp);
    
    int to,from,cost,p_to,p_from;
    for(int i=0;i<v.size();i++){
        to=v[i].first.first;
        from=v[i].first.second;
        cost=v[i].second;
        int temp;
        if(to>from){
            temp=to;
            to=from;
            from=temp;
        }
        p_to=find_parent(to);
        p_from=find_parent(from);
        if(p_to!=p_from){
            parent[p_from]=p_to;
            ans+=cost;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    init();
    solution();
    cout<<ans;
    return 0;
}
