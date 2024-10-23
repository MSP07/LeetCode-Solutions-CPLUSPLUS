 /*approach
  binary search approach
  brute force is a linear search that will cost 0(n sqaure)
  instead we can take advantage of sorted rows and cols and
  start from first row and last col if the target is found return true
  else if val < target move down to match the val that is row++
  else move up to match the val that is col-- and after all this till
  the target is not found then return false*/ 
class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix,int target){
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m-1;
        while(row<n && col>=0){
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]<target){
                row++;
            }else{
                col--;
            }
        }
        return false;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
