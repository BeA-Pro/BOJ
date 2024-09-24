import java.util.*;
import java.io.*;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
	
	private static class hole{
		int y1,x1,y2,x2;
		hole (int y1,int x1, int y2, int x2){
			this.y1 = y1;
			this.x1 = x1;
			this.y2 = y2;
			this.x2 = x2;
		}
	}
	static int N;
	static int[][] map;
	static hole[] holeInfo;
	static int[] dy = {-1,1,0,0}, dx = {0,0,-1,1};
	// 상 하 좌 우 
	
	
	private static int simulation(int sy, int sx, int dir) {
		int cnt = 0;
		int y = sy, x = sx;
		while(true) {
//			System.out.println(y+" "+x);
			y+=dy[dir];
			x+=dx[dir];
			if((y == sy && x == sx) || map[y][x] == -1 ) break;
			if(map[y][x] == 0) continue;
				
			if(map[y][x] == 1) {
				if(dir == 0) dir = 1; // 상 -> 하
				else if(dir == 1) dir = 3; // 하 -> 우
				else if(dir == 2) dir = 0; // 좌 -> 상
				else dir = 2; // 우 -> 좌 
				cnt++;
			}else if(map[y][x] == 2) {
				if(dir == 0) dir = 3; // 상 -> 우
				else if(dir == 1) dir = 0; // 하 -> 상 
				else if(dir == 2) dir = 1; // 좌 -> 하
				else dir = 2; // 우 -> 좌 
				cnt++;
			}else if(map[y][x] == 3) {
				if(dir == 0) dir = 2; // 상 -> 좌  
				else if(dir == 1) dir = 0; // 하 -> 상 
				else if(dir == 2) dir = 3; // 좌 -> 우
				else dir = 1;// 우 -> 하  
				cnt++;
			}else if(map[y][x] == 4) {
				if(dir == 0) dir = 1; // 상 -> 하
				else if(dir == 1) dir = 2; // 하 -> 좌 
				else if(dir == 2) dir = 3; // 좌 -> 우
				else dir = 0; // 우 -> 상
				cnt++;
			} else if(map[y][x] == 5) {
				if(dir == 0) dir = 1; // 상 -> 하
				else if(dir == 1) dir = 0; // 하 -> 상 
				else if(dir == 2) dir = 3; // 좌 -> 우
				else dir = 2; // 우 -> 좌 
				cnt++;
			} else {
				int num = map[y][x];
				if(y == holeInfo[num].y1 && x == holeInfo[num].x1) {
					y = holeInfo[num].y2;
					x = holeInfo[num].x2;
				}else {
					y = holeInfo[num].y1;
					x = holeInfo[num].x1;
				}
			}
		}
		// System.out.println("done");
		return cnt;
	}
	
	
	
	public static void main(String args[]) throws Exception
	{
		// System.setIn(new FileInputStream("res/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
		   5 5 5 5 5
		   5 1 1 1 5
		   5 1 1 1 5
		   5 1 1 1 5
		   5 5 5 5 5
		   
		   0 1 2 3 4
		   3
		*/

		for(int test_case = 1; test_case <= T; test_case++)
		{
			String[] input;
			N = Integer.parseInt(br.readLine().trim());
			map = new int[N+2][N+2];
			holeInfo = new hole[11];
			int answer = 0;
			for(int i = 0; i < N + 2; i++) {
				map[0][i] = 5;
				map[i][0] = 5;
				map[N+1][i] = 5;
				map[i][N+1] = 5;
			}

			for(int i = 1;i < N + 1;i++) {
				input = br.readLine().trim().split(" ");
				for(int j = 1; j<N+1;j++) {
					map[i][j] = Integer.parseInt(input[j-1]);
					if(map[i][j]>=6) {
						if(holeInfo[map[i][j]] == null) holeInfo[map[i][j]] = new hole(i,j,-1,-1);
						else {
							holeInfo[map[i][j]].y2 = i;
							holeInfo[map[i][j]].x2 = j;
						}
					}
				}
			}
			
			for(int i=1;i<N+1;i++) {
				for(int j=1;j<N+1;j++) {
					if(map[i][j] == 0) {
						for(int k=0;k<4;k++) {
							answer = Math.max(answer, simulation(i,j,k));
						}
					}
				}
			}
			System.out.printf("#%d %d\n",test_case,answer);
		}
	}
}