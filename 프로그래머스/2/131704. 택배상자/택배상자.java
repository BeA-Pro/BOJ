import java.util.*;

class Solution {
    public int solution(int[] order){
        int answer = 0;
        ArrayList<Integer> numbers = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        for(int i=0;i<order.length;i++) numbers.add(i+1);
        int index = 0;
        for(int i=0;i<order.length;i++){
            if(index!=numbers.size() && numbers.get(index) == order[i]){
                answer++;
                index++;
            }else if(!stack.isEmpty() && stack.peek() == order[i]){
                stack.pop();
                answer++;
            }else{
                if(index == numbers.size() && stack.peek() != order[i]) break;
                if(index != numbers.size()) stack.add(numbers.get(index++));
                i--;
            }
        }
        
        return answer;
    }
}