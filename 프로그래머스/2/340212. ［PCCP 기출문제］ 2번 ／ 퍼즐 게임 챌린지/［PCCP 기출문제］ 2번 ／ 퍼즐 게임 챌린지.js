function solution(diffs, times, limit) {
    var answer = 0;
    let left = 1, right = 0;
    
    for(diff of diffs) right = Math.max(right,diff);
    answer = right;
    
    while(left<=right){
        const level = parseInt((left+right)/2);
        let sum = times[0];
        
        for(let i = 1; i < diffs.length;i++){
            if(level>=diffs[i]) sum+=times[i];
            else sum += (times[i]+times[i-1])*(diffs[i]-level)+times[i];
        }
        
        if(sum <= limit){
            answer = Math.min(answer,level);
            right = level-1;
        }else left = level+1;
    }
    return answer;
}