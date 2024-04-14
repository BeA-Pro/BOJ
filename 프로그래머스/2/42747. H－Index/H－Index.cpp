#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    for(int i=0;i<citations.size();i++){
        int cnt = citations.size() - i;
        if(cnt >= citations[i]) answer = max(answer, citations[i]);
        else answer = max(answer,cnt);
        
    }
    return answer;
}