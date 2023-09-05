#include <string>
#include <vector>
using namespace std;

int parent[201];

int find_parent(int n){
    if(parent[n] == n) return n;
    return parent[n] = find_parent(parent[n]);
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<pair<int,int> > v;
    for(int i = 0; i < 201 ;i++) parent[i] = i;
    
    for(int i = 0 ; i < computers.size(); i++){
        for(int j = i+1; j < computers[i].size();j++){
            if(computers[i][j]) v.push_back(make_pair(i,j));
        }
    }
    
    for(int i=0;i<v.size();i++){
        int a = v[i].first, b = v[i].second;
        int parent_a = find_parent(a), parent_b = find_parent(b);
        if(parent_a!=parent_b){
            parent[parent_b] = parent_a;
            n--;
        }
    }
    return n;
}