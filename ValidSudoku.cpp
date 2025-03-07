/*approach
  bit manipulation, hashmap
  we keep three hashmaps rows, cols, boxes
  each for checking repeated elements in their names
  for boxes we actually find the ind or rather the sub box that we r searching
  and if on any of these three hashmaps if there r repeated vals we return false
  and we update by bits and finally we return true*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0}, columns[9] = {0}, boxes[9] = {0};
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j] == '.') continue;
                int num = board[i][j]-'1';
                int mask = 1 << num;       
                int boxIndex = (i / 3) * 3 + j / 3;
                if (rows[i] & mask || columns[j] & mask || boxes[boxIndex] & mask) {
                    return false;
                }
                rows[i] |= mask;
                columns[j] |= mask;
                boxes[boxIndex] |= mask;
            }
        }
        return true;
    }
};
