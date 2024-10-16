function solution(bandage, health, attacks) {
    var answer = 0;
    const t = bandage[0];
    const x = bandage[1];
    const y = bandage[2];
    
    let cur_health = health;
    let att_index = 0;
    let care_time = 0;
    
    for(let i = 1; i <= 1000; i++){
        if(att_index == attacks.length) break;
        if(attacks[att_index][0] == i){
            cur_health-=attacks[att_index][1];
            if(cur_health <= 0) break;
            att_index+=1;
            care_time = 0;
        } else {
            care_time+=1;
            if(care_time % t == 0){
                cur_health = Math.min(health, cur_health + y);
                care_time = 0;
            }
            cur_health = Math.min(health, cur_health + x);
        }
    }
    if(cur_health <= 0) return -1;
    return cur_health;
}