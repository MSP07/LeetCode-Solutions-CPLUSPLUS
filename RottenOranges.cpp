/*approach
  bfs approach
  we start by calcu the total infected oranges and total oranges normal
  the first infected orange is pushed inside the q we start iterating there
  for every four directional cell present surrounding the infected cell if the surrounded cell is fresh or 1
  then it will become infected i.e 2 and the time for that will be updated to mins+1 whereas simulataneously
  total oranges count will be decreased and time taken to finish all fresh oranges to infected are updated 
  and finally if there are no fresh oranges we return the time taken else we return -1*/
struct Cell{
    int x,y,Mins;
};

class Solution{
public:
    int orangesRotting(vector<vector<int>>& grid){
        int totalOranges = 0, infectedOranges = 0;
        queue<Cell>q;
        vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                    ++infectedOranges;
                }
                if(grid[i][j]==1) ++totalOranges;
            }
        }

        if(totalOranges==0)return 0;
        if(infectedOranges==0)return -1;

        int minMinutes = 0;

        while(!q.empty()){
            Cell curr = q.front();
            q.pop();

            for(auto& dir:dirs){
                int newX = curr.x + dir[0];
                int newY = curr.y + dir[1];
                if(newX>=0 && newY>=0 && newX<grid.size() && newY<grid[0].size() && grid[newX][newY]==1){
                    grid[newX][newY] == 2;
                    totalOranges--;
                    q.push({newX,newY,curr.Mins+1});
                    minMinutes = curr.Mins + 1;
                }
            }
        }

        return totalOranges == 0 ? minMinutes : -1;
    }
};
