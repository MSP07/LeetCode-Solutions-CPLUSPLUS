/*approach
  sorting, simulation
  goal is to take highest in each row and sum it up so we sort each row in descending order
  then take the highest of that particular column and add it to ans then iterate and finally 
  return the ans*/
class Solution{
public:
    int deleteGreatestValue(vector<vector<int>>& grid){
        int n=grid.size(), m =grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            sort(grid.begin(),grid.end(),greater<int>());
        }
        for(int i=0;i<m;i++){
            int maxi=0;
            for(int j=0;j<n;j++){
                maxi=max(maxi,grid[j][i]);
            }
            ans+=maxi;
        }
        return ans;
    }
};
