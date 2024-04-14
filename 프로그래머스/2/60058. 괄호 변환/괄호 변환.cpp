#include <string>
#include <vector>
#include <stack>
using namespace std;

string recursion(string p, int s_index){
    if(s_index==p.size()) return "";
    stack<char> s;
    
    string tmp ="";
    
    
    int left = 0, right = 0, index = s_index;
    if(p[index] == '(') left++;
    else right++;
    
    s.push(p[index++]);
    
    while(left!=right && !s.empty()){
        if(p[index] == '(') left++;
        else right++;
        
        if(s.top() == '(' && p[index] == ')') s.pop();
        else s.push(p[index]);
        index++;
    }
    
    if(s.empty()) tmp = p.substr(s_index, index - s_index) + recursion(p,index);
    else{
        tmp = "(";
        tmp += recursion(p,index);
        tmp +=")";
        for(int i = s_index + 1; i < index - 1; i++){
            if(p[i] == '(') tmp.push_back(')');
            else tmp.push_back('(');
        }
    }
    return tmp;
}

string solution(string p) {
    string answer = "";

    answer = recursion(p,0);
    return answer;
}