/*approach
  greedy
  to be palindromic the pattern will be [0][0] it will be [0][n-1]
  then for [0][1] it will be [0][n-2] similarly for cols [0][0] it will
  be [0][m-1] and so on. so we check for rows and cols to be flipped
  if grid[i][j] != grid[i][m-j-1] rowFlips++ and similarly 
  grid[i][j] != grid[n-i-1][j] colFlips++ we return the min of the both*/
class Solution{
public:
    int minFlips(vector<vector<int>>& grid){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = grid.size();
        int m = grid[0].size();
        int rowFlips = 0;
        int colFlips = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m/2;++j){
                if(grid[i][j] != grid[i][m-j-1]){
                    rowFlips++;
                }
            }
        }
        for(int j=0;j<m;++j){
            for(int i=0;i<n/2;++i){
                if(grid[i][j] != grid[n-i-1][j]){
                    colFlips++;
                }
            }
        }
        return min(rowFlips,colFlips);
    }
};
