/*approach
  dp-approach
  we use tabulation we iterate through the matrix and if its first row or first col related and val is 1
  then we keep dp[i][j] as 1 else we take the size as min(top cell,left cell, top left cell) and add 1
  so if all are 1 then with the curr cell it forms a cell of size 2 else the cell size will be 1 only with this
  we keep track of max cell size and the maximum square will be square of that max value.
  We space optimise this approach and return the answer*/
class Solution{
public:
    int maximalSquare(vector<vector<char>>& matrix){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int>curr(cols,0),prev(cols,0);
        int maxSize = 0;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(matrix[i][j]==1){
                    if(i==0 or j==0){
                        curr[j] = 1;
                    }else{
                        curr[j] = min({prev[j],prev[j-1],curr[j-1]})+1;
                        maxSize = max(maxSize,curr[j]);
                    }
                }
            }
            prev = curr;
        }
        return maxSize*maxSize;
    }
};
