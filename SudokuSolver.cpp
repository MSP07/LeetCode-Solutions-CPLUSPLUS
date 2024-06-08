//approach
//if we find a empty spot we iterate from 1 to 9 to find a number for the spot
//we check whether the number is already present in any other cell
//if not we make it a possibility and convert it again to . while backtracking to find more other possibilities
//if either the digit is present somewhere else or no perfect match is found for that particular spot we return false
//else after full iteration the spots are all fully filled we return true hence returning the new matrix
class Solution{
private:
    bool isValid(vector<vector<string>>& board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c)return false;
            if(board[row][i]==c)return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;
        }
        return true;
    }

    bool solve(vector<vector<string>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board))return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<string>>& board){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        solve(board);
    }
};
