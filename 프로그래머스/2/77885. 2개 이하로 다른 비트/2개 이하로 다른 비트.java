class Solution {
    public long[] solution(long[] numbers) {
        long[] answer = new long[numbers.length];
        for (int i = 0; i < numbers.length; i++) {
            long num = numbers[i];
            long bit = 1;
            
            while (true) {
                if ((bit & num) == 0) {
                    num |= bit;
                    num ^= (bit >> 1);
                    break;
                }
                bit <<= 1;
            }
            
            answer[i] = num; // 배열의 현재 인덱스에 num 값을 할당
        }
        return answer;
    }
}