import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
class Solution {
    public int[] solution(int[] fees, String[] records) {
        int[] answer;
        TreeMap<String, Integer> tr = new TreeMap<>();
        HashMap<String, String> info = new HashMap<>();
        
        for(int i=0;i<records.length;i++){
            String time = records[i].split(" ")[0];
            String num = records[i].split(" ")[1];
            String act = records[i].split(" ")[2];
            if(act.equals("IN")){
                info.put(num,time);
            }else{
                String in_time = info.get(num);
            
                String inH = in_time.split(":")[0];
                String inM = in_time.split(":")[1];
                String oH = time.split(":")[0];
                String oM = time.split(":")[1];
                int min = (Integer.parseInt(oH) - Integer.parseInt(inH)) * 60 + (Integer.parseInt(oM) - Integer.parseInt(inM));
                
                if(tr.containsKey(num)) tr.put(num, tr.get(num) + min);
                else tr.put(num,min);
                info.remove(num);
            }
            
        }
        info.forEach((key,value)->{
            String inH = value.split(":")[0];
            String inM = value.split(":")[1];
            int min = (23 - Integer.parseInt(inH)) * 60 + (59 - Integer.parseInt(inM));
            
            if(tr.containsKey(key)) tr.put(key, tr.get(key) + min);
            else tr.put(key,min);
        });
        
        answer = new int[tr.size()];
        AtomicInteger index = new AtomicInteger(0);
        
        tr.forEach((key,value)->{
            int idx = index.getAndIncrement();
            answer[idx] += fees[1];
            int over_time = value - fees[0];
            if(over_time > 0){
                answer[idx] += over_time / fees[2] * fees[3];
                if(over_time % fees[2] != 0) answer[idx] += fees[3];
            }
        });
        
        return answer;
    }
}