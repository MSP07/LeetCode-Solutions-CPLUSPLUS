/*approach
  iterate through rows first and find the max element
  then update the answer with that*/
class Solution{
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid){
        int n = grid.size();
        vector<vector<int>> maxLocal(n-2,vector<int>(n-2));
        vector<vector<int>> maxRow(n,vector<int>(n-2));
        for(int i=0;i<n;i++){
            for(int j=0;j<n-2;j++){
                maxRow[i][j] = max({grid[i][j],grid[i][j+1],grid[i][j+2]});
            }
        }
        
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                maxLocal[i][j] = max({maxRow[i][j],maxRow[i+1][j],maxRow[i+2][j]});
            }
        }
        return maxLocal;
    }
};
