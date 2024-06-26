import java.util.*;
import java.io.*;

class Info{
    int cost,to;
    Info(int to, int cost){
        this.to = to;
        this.cost = cost;
    }
}

public class Main {
    static int T,n,d,c;
    static int[] dist;
    static ArrayList<ArrayList<Info>> graph;
    static PriorityQueue<Info> pq;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        String[] input;

        Comparator<Info> infoComparator = new Comparator<Info>() {
            @Override
            public int compare(Info o1, Info o2) {
                return Integer.compare(o1.cost,o2.cost);
            }
        };

        while(T-- > 0){
            input = br.readLine().split(" ");
            n = Integer.parseInt(input[0]);
            d = Integer.parseInt(input[1]);
            c = Integer.parseInt(input[2]);
            graph = new ArrayList<ArrayList<Info>>();
            dist = new int[n+1];
            for(int i=0;i<=n;i++) {
                graph.add(new ArrayList<Info>());
                dist[i] = Integer.MAX_VALUE;
            }
            int a,b,s;
            for(int i=0;i<d;i++){
                input = br.readLine().split(" ");
                a = Integer.parseInt(input[0]);
                b = Integer.parseInt(input[1]);
                s = Integer.parseInt(input[2]);
                graph.get(b).add(new Info(a,s));
            }

            pq = new PriorityQueue<>(infoComparator);

            dist[c] = 0;
            pq.add(new Info(c,0));

            int cnt = 0;
            int time = 0;
            while (!pq.isEmpty()){
                Info cur = pq.poll();
                if(cur.cost > dist[cur.to]) continue;
                cnt++;
                time = Math.max(time,cur.cost);
                for(Info i : graph.get(cur.to)){
                    if(dist[i.to] > cur.cost + i.cost){
                        dist[i.to] = cur.cost + i.cost;
                        pq.add(new Info(i.to, cur.cost + i. cost));
                    }
                }
            }
            System.out.printf("%d %d\n",cnt,time);


        }


    }
}
