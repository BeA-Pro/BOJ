import java.util.*;

class Info{
    int pos, dist;
    Info (int pos, int dist){
        this.pos = pos;
        this.dist = dist;
    }
}

class Solution {
    static ArrayList<Integer>[] tree;
    static int[] dist;
    
    public static void dijkstra(int dest){
        PriorityQueue<Info> pq = new PriorityQueue<>((a,b) -> a.dist - b.dist);
        pq.add(new Info(dest,0));
        dist[dest] = 0;
        
        while(!pq.isEmpty()){
            Info cur = pq.poll();
            if(dist[cur.pos] < cur.dist) continue;
            for(int next : tree[cur.pos]){
                if(cur.dist+1 < dist[next]){
                    dist[next] = cur.dist + 1;
                    pq.add(new Info(next, cur.dist + 1));
                }
            }
        }
    }
    
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];
        tree = new ArrayList[n+1];
        dist = new int[n+1];
        for(int i=1;i<=n;i++){
            tree[i] = new ArrayList<>();
            dist[i] = Integer.MAX_VALUE;
        }
        
        for(int[] road : roads){
            tree[road[0]].add(road[1]);
            tree[road[1]].add(road[0]);
        }
        dijkstra(destination);
 
        for(int i=0;i<sources.length;i++){
            if(dist[sources[i]] == Integer.MAX_VALUE) answer[i] = -1;
            else answer[i] = dist[sources[i]];
        }
        
        return answer;
    }
}