/*approach
  dfs, matrix
  aim to count the max fish in a surrounding region and we can
  achieve this by using dfs similar to flood fill problem and
  we mark the cells that are visited and calculate in neighborhood
  if there is any fish if so we sum them up and keep track of max one
  finally returning it*/
class Solution {
    vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
private:
    int dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]==0)return 0;
        int ans = grid[i][j];
        grid[i][j] = 0;
        for(auto& dir:dirs){
            ans += dfs(i+dir[0],j+dir[1],grid);
        }
        return ans;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int fishes = INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]>0){
                    fishes = max(fishes,dfs(i,j,grid));
                }
            }
        }
        return fishes == INT_MIN ? 0 : fishes;
    }
};
