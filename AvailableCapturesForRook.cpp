/*approach
  simulation, bfs
  we start our search when we come across a rook
  iterate four ways and when come across a bishop break the loop
  come across a pawn increase the pawns and break the loop and finally return the pawns*/
class Solution{
    vector<vector<int>>dirs={{-1,0},{1,0},{0,-1},{0,1}};
public:
    int numRookCaptures(vector<vector<char>>& board){
        int pawns = 0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    for(auto& dir:dirs){
                        int x=i+dir[0],y=j+dir[1];
                        while(x>=0 && y>=0 && x<8 && y<8){
                            if(board[x][y]=='B')break;
                            if(board[x][y]=='p'){
                                ++pawns;
                                break;
                            }
                            x+=dir[0];
                            y+=dir[1];
                        }
                    }
                }
            }
        }
        return pawns;
    }
};
