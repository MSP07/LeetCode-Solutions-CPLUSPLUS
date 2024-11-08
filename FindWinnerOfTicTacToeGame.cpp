/*approach
  hashmap, simulation
  we first create a matrix of same dimensions of tic tac toe game then
  fill it with given moves table and after that if any of the three row,col,diag
  has same 'A' or 'B' we return true indicating A or B has won else we return Draw
  if all the 9 are filled and no result if 9 is not filled then we return Pending*/
class Solution {
private:
    bool checkWin(vector<vector<char>>& grid, int row, int col) {
        char player = grid[row][col];
        if (grid[row][0] == player && grid[row][1] == player && grid[row][2] == player) return true;
        if (grid[0][col] == player && grid[1][col] == player && grid[2][col] == player) return true;
        if (row == col && grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) return true;
        if (row + col == 2 && grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) return true;
        return false;
    }
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> grid(3, vector<char>(3, ' '));
        for (int i = 0; i < moves.size(); ++i) {
            int row = moves[i][0], col = moves[i][1];
            grid[row][col] = (i % 2 == 0) ? 'X' : 'O'; 
            if (checkWin(grid, row, col)) {
                return (i % 2 == 0) ? "A" : "B";
            }
        }
        if (moves.size() == 9) return "Draw";
        return "Pending";
    }
};
