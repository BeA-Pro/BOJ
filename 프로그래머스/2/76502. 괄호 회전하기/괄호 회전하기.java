import java.util.*;
class Solution {
    public int solution(String s) {
        int answer = 0;
        for(int i=0;i<s.length();i++){
            LinkedList<Character> stack = new LinkedList<>();
            for(int j=0;j<s.length();j++){
                int idx = (i+j)%s.length();
                 //System.out.printf("%d\n",idx);
                
                if(stack.isEmpty()){
                    stack.addFirst(s.charAt(idx));
                    continue;
                }
                // System.out.println(stack.peek()+" "+s.charAt(idx));
                
                if(s.charAt(idx)==']' && stack.peek()=='[') stack.remove();
                else if(s.charAt(idx)=='}' && stack.peek() == '{') stack.remove();
                else if(s.charAt(idx)==')' && stack.peek() == '(') stack.remove();
                else stack.addFirst(s.charAt(idx));
            }
            // System.out.println(stack.size());
            if(stack.isEmpty()) answer+=1;
        }
        return answer;
    }
}