#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int pl[1001];
int mi[1001];

int solution(vector<int> number) {
    int answer = 0;
    
    for(int i=0;i<number.size();i++){
        for(int j=i+1;j<number.size();j++){
            for(int k = j+1;k<number.size();k++){
                if(number[i]+number[j]+number[k]==0) answer++;
            }
        }
    }
    
    return answer;
}