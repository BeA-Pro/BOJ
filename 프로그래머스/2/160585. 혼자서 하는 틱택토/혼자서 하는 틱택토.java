class Solution {
    
    public boolean checkWin(char[][] board, char player) {
        // Check rows, columns and diagonals for a win
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
        return false;
    }

    public int solution(String[] boardStr) {
        char[][] board = new char[3][3];
        int countO = 0, countX = 0;

        // Convert input board and count 'O's and 'X's
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = boardStr[i].charAt(j);
                if (board[i][j] == 'O') countO++;
                else if (board[i][j] == 'X') countX++;
            }
        }

        // Check basic count conditions
        if (countX > countO || countO > countX + 1) {
            return 0;
        }

        boolean winO = checkWin(board, 'O');
        boolean winX = checkWin(board, 'X');

        // Check win conditions
        if (winO && countO != countX + 1) return 0;
        if (winX && countO != countX) return 0;
        if (winO && winX) return 0;

        return 1;
    }
}