import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static class pos{
        int y, x;
        pos(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
    static int n;
    static char[][] info;
    static boolean flag = false;
    static ArrayList<pos> teacher = new ArrayList<>();

    private static void cal(int num,int cnt){
        if(cnt == 3){
//            for(int i = 0; i< n;i++){
//                for(int j=0; j<n;j++){
//                    System.out.printf("%c ", info[i][j]);
//                }
//                System.out.println();
//            }
//            System.out.println();
            boolean temp = false;
            for(pos a : teacher){
                // 위로
                int cur = a.y;
                while(cur >= 0){
                    if(info[cur][a.x] == 'S') temp = true;
                    else if(info[cur][a.x] == 'O') break;
                    cur-=1;
                }

                // 아래
                cur = a.y;
                while(cur < n){
                    if(info[cur][a.x] == 'S') temp = true;
                    else if(info[cur][a.x] == 'O') break;
                    cur+=1;
                }

                // 오른쪽
                cur = a.x;
                while(cur < n){
                    if(info[a.y][cur] == 'S') temp = true;
                    else if(info[a.y][cur] == 'O') break;
                    cur+=1;
                }

                // 왼쪽
                cur = a.x;
                while(cur >= 0) {
                    if (info[a.y][cur] == 'S') temp = true;
                    else if (info[a.y][cur] == 'O') break;
                    cur -= 1;
                }
            }
            if(!temp) flag = true;
            return;
        }

        if(num >= n*n) return;

        int y = num/n;
        int x = num%n;
        if(info[y][x] == 'X'){
            info[y][x] = 'O';
            cal(num + 1, cnt + 1);
            info[y][x] = 'X';
        }
        cal(num + 1, cnt);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        info = new char[n][n];

        String[] input;

        for(int i=0;i<n;i++){
            input = br.readLine().split(" ");
            for(int j = 0; j < n; j++){
                info[i][j] = input[j].charAt(0);
                if(info[i][j] == 'T') teacher.add(new pos(i,j));
            }
        }

        cal(0,0);
        if(flag) System.out.println("YES");
        else System.out.println("NO");

    }
}
