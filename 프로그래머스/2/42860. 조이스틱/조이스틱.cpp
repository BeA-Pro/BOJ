#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
    int n = name.size();
    int answer = 0;
    int min_move = n -1;
    
    for(int i=0;i<n;i++){
        answer+=min(name[i]-'A', 'Z' - name[i] + 1);
        int y = i + 1;
        while(y < n && name[y] == 'A') y++;
        
        min_move = min(min_move, i + n - y + min(i, n-y));
    }
    answer+=min_move;
    return answer;
}