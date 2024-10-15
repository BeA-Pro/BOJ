function changeToMin(str){
    let time = str.split(":");
    let min = Number(time[0])*60 + Number(time[1]);
    // console.log(min);
    return min
}

function solution(video_len, pos, op_start, op_end, commands) {
    var answer = '';
    let end = changeToMin(video_len);
    let cur = changeToMin(pos);
    let op_s = changeToMin(op_start);
    let op_e = changeToMin(op_end);
    
    for(const command of commands){
        if(op_s<= cur && cur <= op_e){
                cur = op_e;
            }
        if(command === "prev"){
            cur = Math.max(cur - 10,0);
        }else{
            cur = Math.min(cur + 10,end);
        }

    }
    if(op_s<= cur && cur <= op_e) cur = op_e;
            
    //nconsole.log(cur);
    let hour = parseInt(cur/60);
    let min = parseInt(cur%60);
    let sHour = String(hour), sMin = String(min);
    if(hour < 10) sHour = '0'+sHour;
    if(min < 10) sMin = '0'+sMin;
    
    answer = sHour+":"+sMin;
    
    
    return answer;
}