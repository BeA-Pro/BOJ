import java.util.*;

class Info {
    boolean del;
    int prev, next;
    
    Info(boolean del, int prev, int next) {
        this.del = del;
        this.prev = prev;
        this.next = next;
    }
}

class Solution {
    public String solution(int n, int k, String[] cmd) {
        // 초기화
        StringBuilder answer = new StringBuilder();
        Info[] info = new Info[n];
        Deque<Integer> stack = new LinkedList<>();  // 삭제된 인덱스를 저장하는 스택

        // 노드 연결 초기화
        for (int i = 0; i < n; i++) {
            int prev = -1, next = -1;
            if (i != 0) prev = i - 1;
            if (i != n - 1) next = i + 1;
            info[i] = new Info(false, prev, next);
        }

        // 명령어 처리
        for (String s : cmd) {
            String[] input = s.split(" ");
            if (input[0].equals("U")) {  // 위로 이동
                int x = Integer.parseInt(input[1]);
                while (x != 0) {
                    k = info[k].prev;
                    x--;
                }
            } else if (input[0].equals("D")) {  // 아래로 이동
                int x = Integer.parseInt(input[1]);
                while (x != 0) {
                    k = info[k].next;
                    x--;
                }
            } else if (input[0].equals("C")) {  // 현재 행 삭제
                info[k].del = true;  // 현재 위치 삭제
                stack.push(k);  // 스택에 삭제된 인덱스 저장

                // 이전 노드와 다음 노드 연결
                if (info[k].prev != -1) info[info[k].prev].next = info[k].next;
                if (info[k].next != -1) info[info[k].next].prev = info[k].prev;

                // 삭제 후 다음 노드로 이동, 만약 마지막 노드였다면 이전 노드로 이동
                if (info[k].next != -1) k = info[k].next;
                else k = info[k].prev;
            } else if (input[0].equals("Z")) {  // 최근 삭제 복구
                int restored = stack.pop();  // 가장 최근에 삭제된 행 복구
                info[restored].del = false;

                // 복구된 노드의 이전 노드와 다음 노드를 다시 연결
                if (info[restored].prev != -1) info[info[restored].prev].next = restored;
                if (info[restored].next != -1) info[info[restored].next].prev = restored;
            }
        }

        // 삭제되지 않은 행은 'O', 삭제된 행은 'X'로 표시
        for (int i = 0; i < n; i++) {
            if (info[i].del) {
                answer.append("X");
            } else {
                answer.append("O");
            }
        }

        return answer.toString();
    }
}
