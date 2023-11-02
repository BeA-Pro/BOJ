#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    vector<stack<int>> s;
    stack<int> a;
    
    s.resize(n);
    
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(board[i][j]!=0) s[j].push(board[i][j]);
        }
    }
    
    for(int i=0;i<moves.size();i++){
        if(s[moves[i] - 1].empty()) continue;
        else{
            int cur = s[moves[i]-1].top();
            s[moves[i]-1].pop();
            if(a.empty()) a.push(cur);
            else{
                if(a.top() == cur){
                    answer+=2;
                    a.pop();
                }else a.push(cur);
            }
        }
    }
    return answer;
}