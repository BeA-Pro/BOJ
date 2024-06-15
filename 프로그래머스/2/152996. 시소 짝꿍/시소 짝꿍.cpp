#include <string>
#include <vector>

using namespace std;

long long cnt[1001];

long long solution(vector<int> weights) {
    long long answer = 0;
    int dist[3] = {2,3,4};
    
    for(int i=0;i<weights.size();i++) cnt[weights[i]]++;
    
    for(int i=100;i<=1000;i++){
        if(cnt[i]!=0) answer += (cnt[i] - 1) * cnt[i] / 2;
        for(int j=i+1;j<=1000;j++){
            bool flag = false;
            
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    if( i * dist[k] == j * dist[l]) flag = true;
                }
            }
            if(flag) answer+=cnt[i] * cnt[j];
        }
        // if( i * 2 <= 1000) answer += cnt[i] * cnt[ i * 2 ];
        // if( i * 3 <= 1000) answer += cnt[i] * cnt[ i * 3 ];
        // if( i * 4 <= 1000) answer += cnt[i] * cnt[ i * 4 ];
    }
    
    return answer;
}