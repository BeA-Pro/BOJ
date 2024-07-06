import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] numbers;
    static boolean[] check;
    static char[] oper;
    static int answer = Integer.MIN_VALUE;

//    static ArrayList<Integer> arr = new ArrayList<>();

    static void cal(int idx){
        if(idx >= n/2){

            int[] memo = new int[n/2 + 1];
            for(int i=0;i<n/2+1;i++) memo[i] = numbers[i];

            for(int i=0;i<n/2;i++){
                if(check[i]){
                    if(oper[i] == '+') memo[i] = memo[i + 1] = memo[i] + memo[i+1];
                    else if(oper[i] == '-') memo[i] = memo[i + 1] = memo[i] - memo[i+1];
                    else memo[i] = memo[i+ 1] = memo[i] * memo[i+1];
                }
            }
            int num = memo[0];
            for(int i=0;i<n/2;i++){
                if(!check[i]){
                    if(oper[i] == '+') num+= memo[i+1];
                    else if(oper[i] == '-') num -= memo[i+1];
                    else num *= memo[i+1];
                }
            }

//            for(int i=0;i<n/2;i++) if(check[i]) System.out.printf("%d ",i);
//            System.out.println();
//            for(int i=0;i<n/2;i++) if(!check[i]) System.out.printf("%d ",i);
//            System.out.println();
//            System.out.println(last);
//            System.out.println();
            answer =Math.max(num,answer);
            return;
        }

        //괄호로 묶는 경우
        check[idx] = true;
        cal(idx + 2);
        check[idx] = false;
        cal(idx+1);

    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        numbers = new int [n/2 + 1];
        check = new boolean[n/2 + 1];
        oper = new char[n/2];
        String input = br.readLine();

        for(int i=0;i<n;i++){
            if(i%2==0) numbers[i/2] = input.charAt(i) - '0';
            else oper[i/2] = input.charAt(i);
        }

        cal(0);

        System.out.println(answer);
    }
}
