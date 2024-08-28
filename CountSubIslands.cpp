/*approach
  dfs
  we first iterate and make all the 1's in grid1 to 2
  then we iterate in grid2 for every one we come across we check whether the whole 1 sequence
  is present in grid1 using bool AND condition and if it is we increase subIsland count and 
  finally return it*/
class Solution {
private:
    void isIslands(vector<vector<int>>& grid1,int i,int j){
        if(i<0 || i>=grid1.size() || j<0 || j>=grid1[i].size() || grid1[i][j]!=1)return;
        grid1[i][j] = 2;
        isIslands(grid1,i+1,j);
        isIslands(grid1,i-1,j);
        isIslands(grid1,i,j+1);
        isIslands(grid1,i,j-1);
    }
    bool isSubIsland(vector<vector<int>>& grid2,vector<vector<int>>& grid1,int i,int j){
        if(i<0 || i>=grid2.size() || j<0 || j>=grid2[i].size() || grid2[i][j]==0){
            return true;
        }
        if(grid1[i][j] != 2){
            return false;
        }
        bool res = true;
        grid2[i][j] = 0;
        res &= isSubIsland(grid2,grid1,i+1,j);
        res &= isSubIsland(grid2,grid1,i-1,j);
        res &= isSubIsland(grid2,grid1,i,j+1);
        res &= isSubIsland(grid2,grid1,i,j-1);
        return res;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int subIslands = 0;
        for(int i=0;i<grid1.size();++i){
            for(int j=0;j<grid1[i].size();++j){
                isIslands(grid1,i,j);
            }
        }
        for(int i=0;i<grid2.size();++i){
            for(int j=0;j<grid2[i].size();++j){
                if(grid2[i][j]==1 && isSubIsland(grid2,grid1,i,j)){
                    ++subIslands;
                }
            }
        }
        return subIslands;
    }
};
