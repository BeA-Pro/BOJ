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

string S;
int N,P,Q,R;

int s = 0, k = 0, h = 0, sk = 0 ,kh = 0, sh = 0, skh =0;

void input() {
    cin>>N>>P>>Q>>R;
    cin>>S;
    
    for(int i=0;i<N;i++){
        if(S[i] == 'S'){
            if(i+1<N && S[i+1] == 'H'){
                sh++;
                i++;
            }
            else if(i+1<N && S[i+1] == 'K'){
                if(i+2<N && S[i+2] == 'H'){
                    skh++;
                    i+=2;
                }else{
                    sk++;
                    i++;
                }
            }else s++;
        }else if(S[i] == 'K'){
            if( i+1<N && S[i+1] == 'H'){
                kh++;
                i++;
            }else k++;
        }else h++;
    }
    
}

void init() {
}


void solution() {
    //cout<<s<<' '<<k<<' '<<h<<' '<<sk<<' '<<kh<<' '<<sh<<' '<<skh;
    // P Q R
    // s k h
    // sk 해주기
    if(sk > R){
        skh += R;
        R = 0;
    }else{
        skh+=sk;
        R-=sk;
    }
    
    // kh 해주기
    if(kh > P){
        skh += P;
        P = 0;
    }else{
        skh+=kh;
        P -= kh;
    }
    
    // sh 해주기
    if(sh > Q){
        skh += Q;
        Q = 0;
    }else{
        skh+=sh;
        Q-=sh;
    }
    
    vector<int> v;
    
    v.push_back(P);
    v.push_back(Q);
    v.push_back(R);
    
    while(1){
        //cout<<v[0]<<' '<<v[1]<<' '<<v[2]<<'\n';
        int index = 0;
        bool flag1 = false, flag2 = false;
        
        //max 값 찾기
        for(int i=1;i<3;i++)
            if(v[index] < v[i]) index = i;
        //s
        if(index == 0){
            if(v[1] == 0 && v[2] == 0) break;
            //k
            if(v[1] != 0 ){
                if(h!=0){
                    v[0]--;
                    v[1]--;
                    h--;
                    skh++;
                    flag1 = true;
                }
            }
            
            //h
            if(!flag1 && v[2] != 0 ){
                if(k!=0){
                    v[0]--;
                    v[2]--;
                    k--;
                    skh++;
                    flag2 = true;
                }
            }
            
        }else if(index == 1){ // k
            if(v[0] == 0 && v[2] == 0) break;
            //s
            if(v[0] != 0 ){
                if(h!=0){
                    v[0]--;
                    v[1]--;
                    h--;
                    skh++;
                    flag1 = true;
                }
            }
            
            //h
            if(!flag1 && v[2] != 0 ){
                if(s!=0){
                    v[1]--;
                    v[2]--;
                    s--;
                    skh++;
                    flag2 = true;
                }
            }
        }else{
            // h
            if(v[0] == 0 && v[1] == 0) break;
            //s
            if(v[0] != 0 ){
                if(k!=0){
                    v[0]--;
                    v[2]--;
                    k--;
                    skh++;
                    flag1 = true;
                }
            }
            
            //k
            if(!flag1 && v[1] != 0 ){
                if(s!=0){
                    v[1]--;
                    v[2]--;
                    s--;
                    skh++;
                    flag2 = true;
                }
            }
        }
        if(!flag1 && !flag2) break;
    }
    
    skh+=min(v[0],min(v[1],v[2]));
    
    cout<<skh;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solution();
    return 0;
}
