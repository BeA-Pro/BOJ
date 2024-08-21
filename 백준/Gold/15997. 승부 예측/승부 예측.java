import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;



public class Main {
    static double[][] win;
    static double[][] draw;
    static double[][] lose;
    static HashMap<String, Integer> team;
    static boolean[][] visit;
    static int score[];
    static double result[];

    private static class G3_15997_info{
        int score;
        int idx;
        G3_15997_info(int a, int b){
            this.score = a;
            this.idx = b;
        }
    }
    static int num = 0;
    static int [][] matches = {
            {0, 1},
            {0, 2},
            {0, 3},
            {1, 2},
            {1, 3},
            {2, 3}
    };
    static void dfs(int cnt,double per){

        if (cnt == 6) {
//            num++;
//            System.out.println(num + " " + per);
            ArrayList<G3_15997_info> ar = new ArrayList<>();
            for (int i = 0; i < 4; i++) ar.add(new G3_15997_info(score[i], i));
            Collections.sort(ar, (a, b) -> b.score - a.score);

            if (ar.get(0).score == ar.get(1).score && ar.get(1).score == ar.get(2).score && ar.get(2).score == ar.get(3).score) {
                result[ar.get(0).idx] += per / 2;
                result[ar.get(1).idx] += per / 2;
                result[ar.get(2).idx] += per / 2;
                result[ar.get(3).idx] += per / 2;
            } else if (ar.get(0).score == ar.get(1).score && ar.get(1).score == ar.get(2).score) {
                result[ar.get(0).idx] += per * (2.0 / 3.0);
                result[ar.get(1).idx] += per * (2.0 / 3.0);
                result[ar.get(2).idx] += per * (2.0 / 3.0);
            } else if (ar.get(0).score == ar.get(1).score) {
                result[ar.get(0).idx] += per;
                result[ar.get(1).idx] += per;
            } else {
                result[ar.get(0).idx] += per;
                if (ar.get(1).score == ar.get(2).score && ar.get(2).score == ar.get(3).score) {
                    result[ar.get(1).idx] += per / 3;
                    result[ar.get(2).idx] += per / 3;
                    result[ar.get(3).idx] += per / 3;
                } else if (ar.get(1).score == ar.get(2).score) {
                    result[ar.get(1).idx] += per / 2;
                    result[ar.get(2).idx] += per / 2;
                } else {
                    result[ar.get(1).idx] += per;
                }
            }
            return;
        }

        visit[matches[cnt][0]][matches[cnt][1]] = true;
        score[matches[cnt][0]]+=3;
        dfs(cnt+1,per*win[matches[cnt][0]][matches[cnt][1]]);
        score[matches[cnt][0]]-=3;

        score[matches[cnt][0]]+=1;
        score[matches[cnt][1]]+=1;
        dfs(cnt+1,per*draw[matches[cnt][0]][matches[cnt][1]]);
        score[matches[cnt][0]]-=1;
        score[matches[cnt][1]]-=1;

        score[matches[cnt][1]]+=3;
        dfs(cnt+1,per*lose[matches[cnt][0]][matches[cnt][1]]);
        score[matches[cnt][1]]-=3;
        visit[matches[cnt][0]][matches[cnt][1]] = false;

    }

    public static void main(String[]args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        team = new HashMap<>();
        String[] input = br.readLine().split(" ");
        for(int i=0;i<input.length;i++) team.put(input[i],i);

        win = new double[4][4];
        draw = new double[4][4];
        lose = new double[4][4];
        visit = new boolean[4][4];
        score = new int[4];
        result = new double[4];

        for(int i=0;i<6;i++) {
            input = br.readLine().split(" ");
            int a = team.get(input[0]);
            int b = team.get(input[1]);
            win[a][b] = Double.parseDouble(input[2]);
            lose[b][a] = Double.parseDouble(input[2]);

            draw[a][b] = Double.parseDouble(input[3]);
            draw[b][a] = Double.parseDouble(input[3]);

            lose[a][b] = Double.parseDouble(input[4]);
            win[b][a] = Double.parseDouble(input[4]);
        }

        dfs(0,1);

        for(double re:result) System.out.println(re);
    }
}
