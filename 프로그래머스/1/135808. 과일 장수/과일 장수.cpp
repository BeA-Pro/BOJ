#include <string>
#include <vector>
#include <iostream>
using namespace std;

int count[10];

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    for(int i=0;i<score.size();i++){
        count[score[i]]++;
    }
    int cnt = 0;
    int temp = 0;
    for(int i=k;i>=0;i--){
        while(count[i]){
            count[i]--;
            cnt++;
            if(cnt==m){
                answer+=cnt*i;
                cnt = 0;
            }
        }
    }
    return answer;
}