/*approach
  we declare a hashmap to keep track of the obstacles we iterate through the directions and modify
  our direction accordingly whether command is to rotate left or right then we move to nextX and nextY 
  with the help of directions array and if that path is in obstacles we break the loop then and there
  we update x,y and maxDist as max(maxDist,x*x+y*y) and finally return the maxDist*/
class Solution{
public:
    int robotSim(vector<int>& commands,vector<vector<int>>& obstacles){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<int>> directions ={{-1,0},{1,0},{0,-1},{0,1}};
        set<pair<int,int>>obstaclesHelp;
        int x = 0, y = 0, d = 0;
        int maxDist = 0;
        for(const auto& ob:obstacles){
            obstaclesHelp.insert({ob[0],ob[1]});
        }
        for(int cmd:commands){
            if(cmd==-1){
                d = (d+1)%4;
            }else if(cmd==-2){
                d = (d+3)%4;
            }else{
                for(int i=0;i<cmd;++i){
                    int nextX = x + directions[d][0];
                    int nextY = y + directions[d][1];
                    if(obstaclesHelp.find({nextX,nextY})!=obstaclesHelp.end()){
                        break;
                    }
                    x = nextX;
                    y = nextY;
                    maxDist = max(maxDist,x*x + y*y);
                }
            }
        }
        return maxDist;
    }
};
