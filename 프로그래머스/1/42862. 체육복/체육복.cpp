#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    a.resize(n+1);
    fill(a.begin(), a.end(), 1);
    
    for(int i=0;i<lost.size();i++) a[lost[i]]--;
    for(int i=0;i<reserve.size();i++) a[reserve[i]]++;
    
    for(int i=1;i<=n;i++){
        if(!a[i]){
            if(i-1>=1 && a[i-1]==2){
                a[i-1] = 1;
                a[i] = 1;
            }else if(i+1<=n && a[i+1]==2){
                a[i+1] = 1;
                a[i] = 1;
            }
        }
        if(a[i]) answer++;
    }
    
    
    return answer;
}