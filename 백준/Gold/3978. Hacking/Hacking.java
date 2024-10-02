import java.util.*;
import java.io.*;

 class Main {

     private static String answer;
     private static boolean flag;

     private static void cal(StringBuilder sb, int k,int m, HashSet<String> hs){
         if(flag) return;
         if(sb.length() == m){
             // System.out.println(sb.toString());
             if(hs.contains(sb.toString())) return;
             answer = sb.toString();

             flag = true;
             return;
         }

         for(int i=0;i<k;i++){
            sb.append((char)('a'+ i));
            cal(sb,k,m,hs);
            sb.deleteCharAt(sb.length()-1);
         }
     }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        String[] input;
        while(T--!=0){
            answer ="";
            flag = false;
            input = br.readLine().split(" ");
            int n = Integer.parseInt(input[0]);
            int m = Integer.parseInt(input[1]);
            int k = Integer.parseInt(input[2]);
            HashSet<String> hs = new HashSet<>();
            String s = br.readLine();
            StringBuilder sb;

            for(int i=0;i<=s.length()-m;i++){
                sb = new StringBuilder();
                for(int j = i; j < i + m; j++){
                    sb.append(s.charAt(j));
                }
//                System.out.println(sb.toString());
                hs.add(sb.toString());
            }

//            for(String item : hs) System.out.println(item);

            sb = new StringBuilder();

            cal(sb,k,m,hs);
            System.out.println(answer);
        }

    }
}
