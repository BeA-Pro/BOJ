#include <string>
#include <vector>

using namespace std;

int DP1[1000000];
int DP2[1000000];

int solution(vector<int> money) {
    int answer = 0;
    int size = money.size();
    DP1[0] = money[0];
    
    for(int i=1;i<size;i++){
        if(i<size-1) DP1[i] = max(DP1[i-1],DP1[i-2]+money[i]);
        DP2[i] = max(DP2[i-1],DP2[i-2]+money[i]);
    }
    
    
    return max(DP1[size-2],DP2[size-1]);
}