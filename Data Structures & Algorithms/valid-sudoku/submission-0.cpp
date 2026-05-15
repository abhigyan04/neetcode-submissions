class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, columns;
        map<pair<int, int>, unordered_set<char>> squares;

        for(int i = 0 ; i < board.size() ; i ++)
        {
            for(int j = 0 ; j < board.size() ; j++)
            {
                if(board[i][j] == '.')  continue;

                pair<int, int> squareIndex = {i / 3, j / 3};

                char val = board[i][j];

                if(rows[i].count(val) || columns[j].count(val) || squares[squareIndex].count(val))
                {
                    return false;
                }
                else
                {
                    rows[i].insert(val);
                    columns[j].insert(val);
                    squares[squareIndex].insert(val);
                }
            }
        }

        return true;
    }
};
