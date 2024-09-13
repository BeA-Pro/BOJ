import java.util.*;
import java.io.*;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
	static private class Info{
		int y, x, time, value;
		Info(int y, int x, int time, int value){
			this.y = y;
			this.x = x;
			this.time = time;
			this.value = value;
		}
	}
	
	static int N,M,K;
	static int[][] info;
	static PriorityQueue<Info> deactive,active;
	static Deque<Info> div;
	static Set<String> check;
	static int[] dx = {-1,1,0,0}, dy = {0,0,1,-1};
	
	static String makeString(int y, int x) {
		return Integer.toString(y)+" "+Integer.toString(x);
	}
	
	public static void main(String args[]) throws Exception
	{
		// System.setIn(new FileInputStream("res/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T=Integer.parseInt(br.readLine());

		for(int test_case = 1; test_case <= T; test_case++)
		{
			String[] input = br.readLine().split(" ");
			N = Integer.parseInt(input[0]);
			M = Integer.parseInt(input[1]);
			K = Integer.parseInt(input[2]);
			check = new HashSet<>();
			info = new int[N][M];
			active = new PriorityQueue<>(new Comparator<Info>() {
				@Override
				public int compare(Info a, Info b) {
					return Integer.compare(a.time , b.time);
				}
			});

			deactive = new PriorityQueue<>(new Comparator<Info>() {
				@Override
				public int compare(Info a, Info b) {
					if(a.time == b.time) return Integer.compare(a.value, b.value); 
					return Integer.compare(a.time, b.time);
				}
			});
			div = new LinkedList<>();
			
			for(int i=0;i<N;i++) {
				input = br.readLine().split(" ");
				for(int j = 0; j < M;j++) info[i][j] = Integer.parseInt(input[j]);
			}
			
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					if(info[i][j] == 0) continue;
					check.add(makeString(i,j));
					deactive.add(new Info(i,j,info[i][j],info[i][j]));
				}
			}
			
			int cur_time = 0;
			
			while(cur_time < K) {
				cur_time++;
				// 분열
				while(!div.isEmpty()) {
					Info cur = div.pollLast();
					active.add(new Info(cur.y, cur.x, cur_time + cur.value - 1, cur.value));
					for(int i=0;i<4;i++) {
						int ny = cur.y + dy[i], nx = cur.x + dx[i];
						if(check.contains(makeString(ny,nx))) continue;
						check.add(makeString(ny,nx));
						deactive.add(new Info(ny,nx,cur_time + cur.value,cur.value));
					}
				}
				// 죽음 처리
				while(!active.isEmpty() && active.peek().time <= cur_time) active.poll();
				
				// 비활성화 활성화 처리 
				while(!deactive.isEmpty() && deactive.peek().time <= cur_time) {
					Info cur = deactive.poll();
					//System.out.printf("%d %d %d %d\n",cur.y,cur.x,cur.time,cur.value);
					div.addLast(cur);
				}
				// System.out.printf("cur_time %d\n",cur_time);
				// System.out.printf("%d %d %d\n",active.size(), deactive.size(), div.size());
			}
			
			System.out.printf("#%d %d\n",test_case,active.size() + deactive.size() + div.size());
			

		}
	}
}