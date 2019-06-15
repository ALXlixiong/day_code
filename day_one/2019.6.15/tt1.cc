class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        for(int i = 1;i<board.size();++i)
            board[0][i] += board[0][i-1];
        for(int i = 1;i<board.size();++i)
            board[i][0] += board[i-1][0];
        for(int i = 1;i<board.size();++i)
        {
            for(int j = 1;j<board[0].size();++j)
            {
                board[i][j] = max(board[i-1][j],board[i][j-1]) + board[i][j];
            }
        }
        return board[board.size()-1][board.size()-1];
    }
};
