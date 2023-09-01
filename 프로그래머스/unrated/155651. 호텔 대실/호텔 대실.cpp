#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int,int> > v;

priority_queue<int, vector<int>, greater<int> > pq;

int solution(vector<vector<string>> book_time) {
    int answer = 1;

    
    for(int i=0;i<book_time.size();i++){
        string s_h, s_m, e_h, e_m;
        s_h = s_m = e_h = e_m ="";
        s_h+=book_time[i][0][0], s_h+=book_time[i][0][1];
        s_m+=book_time[i][0][3], s_m+=book_time[i][0][4];
        e_h+=book_time[i][1][0], e_h+=book_time[i][1][1];
        e_m+=book_time[i][1][3], e_m+=book_time[i][1][4];
        v.push_back(make_pair(stoi(s_h)*60+stoi(s_m), stoi(e_h)*60+stoi(e_m)));
    }
    
    sort(v.begin(),v.end());
    
    int cnt = 1;
    pq.push(v[0].second+10);
    
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i].first<<' '<<v[i].second<<'\n';
    // }
    
    for(int i=1;i<v.size();i++){
        if(v[i].first < pq.top()){
            answer = max(answer,++cnt);
            pq.push(v[i].second+10);
        }else{
            // cout<<v[i].first<<'\n';
            // cout<<pq.top()<<'\n';
            while(!pq.empty() && v[i].first >= pq.top()){
                // cout<<pq.top()<<'\n';
                pq.pop();
                cnt--;
            }
            pq.push(v[i].second+10);
            answer = max(answer,++cnt);
        }
    }
    
    
    return answer;
}