#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v;
int b[10];
bool check[10]={false,};

void com(int idx,int cnt,int r){
    if(cnt==r){
        for(int i=0;i<r;i++) printf("%d ",b[i]);
        putchar('\n');
        return;
    }
    if(idx==v.size()) return;
    b[cnt]=v[idx];
    com(idx+1,cnt+1,r);
    com(idx+1,cnt,r);
}


int main(){
    int n,r;
    cin>>n>>r;
    for(int i=0;i<n;i++){
        v.push_back(i+1);
    }
    com(0,0,r);
    return 0;
}