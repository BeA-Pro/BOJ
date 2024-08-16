import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;



public class Main {

    static class info_19238{
        int y,x;

        public info_19238(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
    static int N,M,F;
    static int sy, sx;
    static int ey, ex;
    static int dy[] = {-1,0,1,0}, dx[] = {0,-1,0,1};
    static int road[][];
    static info_19238 info[];
    // static Queue<info_19238> q = new LinkedList<>();

    public static int find(){
        int cost = 0;
        Queue<info_19238> q = new LinkedList<>();
        boolean check[][] = new boolean[N][N];
        q.offer(new info_19238(sy,sx));
        check[sy][sx] = true;

        while(!q.isEmpty()){
            int size = q.size();
            int next_idx = -1;
            for(int a = 0; a < size; a++){
                info_19238 cur = q.poll();
                if(road[cur.y][cur.x] < 0){
                    if(next_idx == -1){
                        sy = cur.y;
                        sx = cur.x;
                        ey = info[-road[cur.y][cur.x]].y;
                        ex = info[-road[cur.y][cur.x]].x;
                        next_idx = -road[cur.y][cur.x];
                        road[cur.y][cur.x] = 0;
                    }else {
                        // 행이 같다면
                        boolean flag = false;
                        if(sy == cur.y){
                            if(cur.x < sx){
                               flag = true;
                            }
                        }else if(cur.y < sy){
                            flag = true;
                        }

                        if(flag){
                            road[sy][sx] = -next_idx;
                            sy = cur.y;
                            sx = cur.x;
                            ey = info[-road[cur.y][cur.x]].y;
                            ex = info[-road[cur.y][cur.x]].x;
                            next_idx = -road[cur.y][cur.x];
                            road[cur.y][cur.x] = 0;
                        }
                    }
                }

                for(int i = 0;i<4;i++){
                    int ny = cur.y + dy[i], nx = cur.x + dx[i];
                    if(0 <= ny && ny < N && 0 <= nx && nx < N && !check[ny][nx] && road[ny][nx] != 1){
                        check[ny][nx] = true;
                        q.offer(new info_19238(ny,nx));
                    }
                }
            }
            if(next_idx!=-1) return cost;
            cost+=1;
        }


        return Integer.MAX_VALUE;
    }

    public static int go(){
        int cost = 0;
        Queue<info_19238> q = new LinkedList<>();
        boolean check[][] = new boolean[N][N];
        q.offer(new info_19238(sy,sx));
        check[sy][sx] = true;

        while(!q.isEmpty()){
            int size = q.size();
            for(int a = 0; a < size; a++){
                info_19238 cur = q.poll();
//                System.out.println("go "+cur.y+" "+cur.x);
                if(cur.y == ey && cur.x == ex){
                    sy = cur.y;
                    sx = cur.x;
                    return cost;
                }

                for(int i = 0;i<4;i++){
                    int ny = cur.y + dy[i], nx = cur.x + dx[i];
                    if(0 <= ny && ny < N && 0 <= nx && nx < N && !check[ny][nx] && road[ny][nx] != 1){
                        check[ny][nx] = true;
                        q.offer(new info_19238(ny,nx));
                    }
                }
            }
            cost+=1;
        }


        return Integer.MAX_VALUE;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        F = Integer.parseInt(input[2]);
        road = new int [N][N];
        info = new info_19238[M+1];
        for(int i = 0; i < N; i ++){
            input = br.readLine().split(" ");
            for(int j = 0; j < N; j++) road[i][j] = Integer.parseInt(input[j]);
        }


        input = br.readLine().split(" ");
        sy = Integer.parseInt(input[0]) - 1;
        sx = Integer.parseInt(input[1]) - 1;

        for(int i = 1; i <= M; i++){
            input = br.readLine().split(" ");
            road[Integer.parseInt(input[0])-1][Integer.parseInt(input[1])-1] = -i;
            info[i] = new info_19238(Integer.parseInt(input[2])-1, Integer.parseInt(input[3])-1);
        }



        for(int i = 0; i < M; i++){
            int cost = find();
//            System.out.println("1 "+ cost);
//            System.out.println(sy + " " +sx + " " + ey + " "+ ex);
            if(F - cost < 0){
                System.out.println(-1);
                return;
            }
            F-=cost;
//            System.out.println(ey+" "+ex);
            cost = go();
//            System.out.println(cost);
//            System.out.println();
            if(F - cost < 0){
                System.out.println(-1);
                return;
            }
            F-=cost;
            F += 2*cost;
        }
        System.out.println(F);


    }
}
