/*approach
  greedy approach
  we start from 0th index after declaring a matrix of given size
  then we choose the min of rowSum[i] and colSum[j] and we subtract
  that value from both rowSum[i] and colSum[j] then we proceed to increase
  pointer on whomever value is 0 the subtracted value remains updated we
  iterate till end. Since we intialise the ans matrix with 0 we don't need to
  worry about the grids that are not being traversed as the sum will always be
  rowSum[i] and colSum[j]*/
class Solution{
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,vector<int>& colSum){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int numRows = rowSum.size();
        int numCols = colSum.size();
        vector<vector<int>> result(numRows,vector<int>(numCols,0));
        int i = 0, j = 0;
        while(i<numRows && j<numCols){
            int val = min(rowSum[i],colSum[j]);
            result[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;
            if(rowSum[i]==0){
                ++i;
            }
            if(colSum[j]==0){
                ++j;
            }
        }
        return result;
    }
};
