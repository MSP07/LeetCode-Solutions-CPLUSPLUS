//approach
//we recursively call the fn till we come to end of the word
//we proceed only if the char in board is equal to word[index]
//then we recursively call the fn on all four sides
//before that we temporarily change char val to * and change back again after 4 side calls
//then we return whether it can proceed(it found new char) or not
class Solution{
private:
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int index){
        if(index==word.length())return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[index])return false;
        char temp = board[i][j];
        board[i][j]='*';
        bool res = dfs(board,word,i+1,j,index+1) || dfs(board,word,i-1,j,index+1) || dfs(board,word,i,j+1,index+1) || dfs(board,word,i,j-1,index+1);
        board[i][j] = temp;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board,string word){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
