class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
       vector<set<int>>rows(9);
        vector<set<int>>cols(9);
       vector<set<int>>boxes(9);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(board[i][j] == '.')
                {
                    continue;
                }
                int box = (i/3)*3 + (j/3);
                if (rows[i].count(board[i][j]) || cols[j].count(board[i][j]) ||
                    boxes[box].count(board[i][j])) {
                    return false;
                } else {
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    boxes[box].insert(board[i][j]);

                }
            }
        }
        return true;
    }
};
