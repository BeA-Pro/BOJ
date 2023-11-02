#include <string>
#include <vector>
#include <iostream>
#define diff 32
using namespace std;

string solution(string new_id) {
    string answer = "";
    // 1단계
    for(int i=0;i<new_id.size();i++){
        if('A'<=new_id[i] && new_id[i]<='Z') new_id[i]+=diff;
    }
    
    // 2단계
    string temp1 ="";
    for(int i=0;i<new_id.size();i++){
        if(('0'<= new_id[i] && new_id[i]<='9') ||('a'<= new_id[i] && new_id[i]<='z') || new_id[i]=='-' || new_id[i]=='_'||new_id[i]=='.') temp1.push_back(new_id[i]);
    }
    //cout<<temp1;
    
    // 3단계
    string temp2 = "";
    if(temp1.size()) temp2.push_back(temp1[0]);
    for(int i=1;i<temp1.size();i++){
        if(temp2[temp2.size()-1] == '.' && temp1[i] == '.') continue;
        temp2.push_back(temp1[i]);
    }
    // cout<<temp2;
    
    // 4단계
    if(temp2.size() && temp2[0] == '.') temp2.erase(temp2.begin());
    if(temp2.size() && temp2[temp2.size()-1] == '.') temp2.pop_back();
    //cout<<temp2;
    
    // 5단계
    if(!temp2.size()) temp2.push_back('a');
    
    // 6단계
    while(temp2.size()>15) temp2.pop_back();
    if(temp2[temp2.size()-1]=='.') temp2.pop_back();
    
    //7단계
    if(temp2.size()<=2){
        char c = temp2[temp2.size()-1];
        while(temp2.size()<3) temp2.push_back(c);
    }
    
    return temp2;
}


// // 6번
//     int size = min(15,new_id.size());
    
//     //5번
//     if(size == 0) return "a";
    
//     if(size <=2){
        
//     }
    
//     for(int i=0;i<size;i++){
//         // 2번
//         if(!(('a'< new_id[i] && new_id[i]<'z') || ('A'<new_id[i] && new_id[i]<'Z') || new_id[i]=='-' || new_id[i]=='_'||new_id[i]=='.')) continue;
        
//         // 4번
//         if((i == 0 || i==size - 1) && new_id[i] == '.') continue;
        
//         char cur = new_id[i];
//         // 3번
//         if(cur == '.' && answer.size()){
//             if(answer[answer.size()-1] == cur) continue;
//         }
        
//         // 1번
//         if('A'< cur && cur<'Z') cur+=diff;
//     }