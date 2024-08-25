/*approach
  dfs
  we use similar approach to no of islands problem
  here instead of whole islands we take area of the connected islands and keep track of the max one
  and return them. we do it by returning 1 each time we encounter an island and finally return it*/
class Solution{
private:
    int isIslands(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)return 0;
        grid[i][j]==0;
        return 1 + isIslands(grid,i+1,j) + isIslands(grid,i-1,j) + isIslands(grid,i,j+1) + isIslands(grid,i,j-1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int maxi = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    maxi = max(maxi,isIslands(grid,i,j));
                }
            }
        }
        return maxi;
    }
};
