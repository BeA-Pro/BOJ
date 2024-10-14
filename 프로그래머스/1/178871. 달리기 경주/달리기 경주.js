function solution(players, callings) {
    var obj = {};
    var answer = players;
    for(let i = 0; i < players.length; i++) obj[players[i]] = i;
    
    for(const name of callings){
        const idx = obj[name];
         [players[idx - 1], players[idx]] = [players[idx], players[idx - 1]];
        obj[name]--;
        obj[players[idx]]++;
        
    }
    
    
    
    
    return answer;
}