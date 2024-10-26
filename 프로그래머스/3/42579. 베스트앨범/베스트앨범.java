import java.util.*;

class Info{
    String genre;
    int total,cnt,index;
    Info (String genre,int total,int cnt, int index){
        this.genre = genre;
        this.total = total;
        this.cnt = cnt;
        this.index = index;
    }
}
class Solution {
    public int[] solution(String[] genres, int[] plays) {
        int[] answer;
        HashMap<String,Integer> genreCnt = new HashMap<>();
        HashMap<String,Integer> checkCnt = new HashMap<>();
        
        ArrayList<Info> ar = new ArrayList<>();
        
        for(int i=0;i<genres.length;i++) genreCnt.put(genres[i],genreCnt.getOrDefault(genres[i],0)+plays[i]);
        
        for(int i=0;i<genres.length;i++) ar.add(new Info(genres[i],genreCnt.get(genres[i]),plays[i],i));
        
        Collections.sort(ar, (a,b)->{
            if(a.total == b.total){
                if(a.cnt == b.cnt) return a.index - b.index;
                return b.cnt - a.cnt;
            }
            return b.total - a.total;
        });
        
        ArrayList<Integer> temp = new ArrayList<>();
        
        for(Info info : ar){
            int a = checkCnt.getOrDefault(info.genre,0);
            if(a == 2) continue;
            checkCnt.put(info.genre,a+1);
            temp.add(info.index);
        }
        
        answer = new int[temp.size()];
        for(int i=0;i<temp.size();i++){
            answer[i] = temp.get(i);
            // System.out.println(temp.get(i));
        }
        
        
        return answer;
    }
}