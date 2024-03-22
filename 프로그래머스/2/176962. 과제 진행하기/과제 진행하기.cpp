#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

typedef struct _info{
    string name;
    int min;
    int left_min;
}Info;

bool cmp(const Info& a, const Info& b){
    return a.min < b.min;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Info> v;
    
    for(int i=0;i<plans.size();i++){
        Info tmp;
        tmp.name = plans[i][0];
        string tmp_hour, tmp_min;
        tmp_hour.push_back(plans[i][1][0]);
        tmp_hour.push_back(plans[i][1][1]);
        tmp_min.push_back(plans[i][1][3]);
        tmp_min.push_back(plans[i][1][4]);
        tmp.min =  stoi(tmp_hour)*60+stoi(tmp_min);
        tmp.left_min = stoi(plans[i][2]);
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),cmp);
    
    stack<Info> stop;
    stack<Info> ready;
    
    for(int i=v.size()-1;i>=1;i--) ready.push(v[i]);
    
    Info cur = v[0];
    while(!stop.empty() || !ready.empty()){
        int end_time = cur.min + cur.left_min;
        bool end_flag = false;
        // 대기 중인 과제가 있는 경우
        if(!ready.empty()){
            if(end_time > ready.top().min) end_flag = true;
        }
            
        if(end_flag){
            cur.left_min = end_time - ready.top().min;
            stop.push(cur);
            cur = ready.top();
            ready.pop();
        }else{
            answer.push_back(cur.name);
            if(!stop.empty() && !ready.empty()){
                if(ready.top().min == end_time){
                    cur = ready.top();
                    ready.pop();
                }else{
                    cur = stop.top();
                    cur.min = end_time;
                    stop.pop();
                }
            }else{
                if(stop.empty()){
                    cur = ready.top();
                    ready.pop();
                }else{
                    cur = stop.top();
                    cur.min = end_time;
                    stop.pop();
                }
            }
        }
    }
    answer.push_back(cur.name);
    
    // for(int i=0;i<v.size();i++) cout<<v[i].name<<' '<<v[i].min<<' '<<v[i].left_min<<'\n';
    return answer;
}