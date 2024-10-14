import java.util.*;

class Formula{
    String left, right, answer, symbol;
    Formula(String left, String right, String answer, String symbol){
        this.left = left;
        this.right = right;
        this.answer = answer;
        this.symbol = symbol;
    }
}
class Solution {
    public String[] solution(String[] expressions) {
        ArrayList<String> answerList = new ArrayList<>();
        
        ArrayList<Formula> com = new ArrayList<>();
        ArrayList<Formula> nCom = new ArrayList<>();

        for(String cur : expressions){
            String input[] = cur.split(" ");
            if(input[4].equals("X")) nCom.add(new Formula(input[0], input[2], input[4], input[1]));
            else com.add(new Formula(input[0], input[2], input[4], input[1]));

        }
        
        boolean[] check = new boolean[10];
        for(int i = 2; i<=9;i++){
            boolean flag = false;
            for(Formula cur : com){
                try{
                    int left = Integer.parseInt(cur.left, i), right = Integer.parseInt(cur.right, i), answer = Integer.parseInt(cur.answer, i);
                    if(cur.symbol.equals("+") && left + right != answer) flag = true;
                    else if(cur.symbol.equals("-") && left - right != answer) flag = true;
                } catch (NumberFormatException e) {
                    flag = true;
                }
               
            }
            check[i] = flag;
        }
        for(int i = 2; i <= 9; i++){
            boolean flag = false;
            for(Formula cur : nCom){
                if(check[i]) continue;
                 
                try{
                    int left = Integer.parseInt(cur.left, i), right = Integer.parseInt(cur.right, i);
                } catch (NumberFormatException e){
                    flag = true;
                }
                check[i] = flag;
            }
        }
        
        //for(int i=2;i<=9;i++) if(!check[i]) System.out.println("Can't change to "+i);
        
         for(Formula cur : nCom){
            boolean flag = false;
            String temp = "";
            for(int i = 2; i <= 9; i++){
                if(check[i]) continue;
    
                    int left = Integer.parseInt(cur.left, i), right = Integer.parseInt(cur.right, i);
                    int answer;
                    if(cur.symbol.equals("+")) answer = left + right;
                    else answer = left - right;

                    if(temp.equals("")) temp = Integer.toString(answer,i);
                    else if(!temp.equals(Integer.toString(answer,i))) flag = true;    
                    
             
                
            }
            if(flag) answerList.add(cur.left+" "+cur.symbol+" "+cur.right+" = ?");
            else answerList.add(cur.left+" "+cur.symbol+" "+cur.right+" = "+temp);
        }
        
        return answerList.toArray(new String[0]);
    }
}