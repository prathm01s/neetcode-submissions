class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // rows
        for (int i = 0;i < 9;i++) {
            vector<int> count(9, 0);
            vector<int> count_(9, 0);
            for (int j = 0;j < 9;j++) {
                if (board[i][j] != '.') {
                    if (++count[board[i][j] - '1'] > 1) return 0;
                }
                if (board[j][i] != '.') {
                    if (++count_[board[j][i] - '1'] > 1) return 0;
                }
            }
        }
        /*
        // columns
        for (int i = 0;i < 9;i++) {
            vector<int> count(9, 0);
            for (int j = 0;j < 9;j++) {
                if (board[j][i] != '.') {
                    if (++count[board[j][i] - '1'] > 1) return 0;
                }
            }
        }*/
        // boxes
        for (int i = 0;i < 2;i++) {
            for (int j = 0;j < 2;j++) {
                vector<int> count(9, 0);
                for (int k = i*3;k < i*3 + 3;k++) {
                    for (int l = j*3;l < j*3 + 3;l++) {
                        if (board[k][l] != '.') {
                            if (++count[board[k][l] - '1'] > 1) return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};
