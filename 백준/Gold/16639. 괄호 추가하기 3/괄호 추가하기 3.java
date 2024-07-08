import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] numbers;
    static char[] oper;
    static int[][] dpMax;
    static int[][] dpMin;

    // 연산자에 따른 계산
    static int operate(int a, int b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                throw new IllegalArgumentException("Invalid operator: " + op);
        }
    }

    // 모든 가능한 괄호 배치를 고려하여 최대값을 계산하는 함수
    static void calculate() {
        for (int i = 0; i <= n / 2; i++) {
            dpMax[i][i] = numbers[i];
            dpMin[i][i] = numbers[i];
        }

        for (int length = 1; length <= n / 2; length++) {
            for (int i = 0; i + length <= n / 2; i++) {
                int j = i + length;
                dpMax[i][j] = Integer.MIN_VALUE;
                dpMin[i][j] = Integer.MAX_VALUE;

                for (int k = i; k < j; k++) {
                    int maxLeft = dpMax[i][k];
                    int minLeft = dpMin[i][k];
                    int maxRight = dpMax[k + 1][j];
                    int minRight = dpMin[k + 1][j];

                    int[] possibleResults = new int[]{
                            operate(maxLeft, maxRight, oper[k]),
                            operate(maxLeft, minRight, oper[k]),
                            operate(minLeft, maxRight, oper[k]),
                            operate(minLeft, minRight, oper[k])
                    };

                    dpMax[i][j] = Math.max(dpMax[i][j], Arrays.stream(possibleResults).max().getAsInt());
                    dpMin[i][j] = Math.min(dpMin[i][j], Arrays.stream(possibleResults).min().getAsInt());
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        numbers = new int[n / 2 + 1];
        oper = new char[n / 2];
        dpMax = new int[n / 2 + 1][n / 2 + 1];
        dpMin = new int[n / 2 + 1][n / 2 + 1];
        String input = br.readLine();

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) numbers[i / 2] = input.charAt(i) - '0';
            else oper[i / 2] = input.charAt(i);
        }

        calculate();

        System.out.println(dpMax[0][n / 2]);
    }
}
