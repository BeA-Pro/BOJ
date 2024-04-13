#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer="";
    answer.push_back(number[0]);
    
    for(int i=1;i<number.size();i++){
        while(answer.size()!=0 && answer[answer.size()-1] < number[i] && number.size() - i != number.size() - k - answer.size()) answer.pop_back();
        answer.push_back(number[i]);
    }
    
    if(answer.size() > number.size() - k) answer.pop_back();
    
    return answer;
}