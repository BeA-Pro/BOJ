#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#define MAX 1000000000
using namespace std;



int solution(int N, int number) {
    int answer = 0;
    unordered_set<int> dp[8];
    int tmp = N;
    int cnt = 0;
    
    for(int i=0;i<8;i++){
        dp[i].insert(tmp);
        tmp = tmp*10 + N;
    }
    
    for(int i=1;i<8;i++){
        for(int j = 0; j<i;j++){
            for(int a : dp[j]){
                for(int b : dp[i - j - 1]){
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if(b != 0 && a%b == 0) dp[i].insert(a/b);
                }
            }
        }
    }
    
    for(int i=0;i<8;i++){
        for(int a : dp[i]){
            if(a == number){
                return i + 1;
            }
        }
    }
    
    return -1;
}