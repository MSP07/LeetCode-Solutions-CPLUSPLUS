/*approach
  greedy
  we count the negatives same time calculating totalSum and finding minimum element with abs value
  if he negatives is even then we can somehow manipulate the matrix to give us the totalSum else
  we remove the min element two times since we have included that in totalSum while calculating total sum of matrix
  and apart from that we need to remove it again once and we finally return the totalSum*/
class Solution{
public:
    long long maxMatrixSum(vector<vector<int>>& matrix){
        long long totalSum = 0;
        int min_abs_val = INT_MAX;
        long long negatives = 0;

        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix.size();++j){
                int grid = matrix[i][j];
                totalSum += abs(grid);
                if(grid<0){
                    ++negatives;
                }
                min_abs_val = min(min_abs_val,abs(grid));
            }
        }

        if(negatives%2){
            totalSum -= 2*min_abs_val;
        }
        
        return totalSum;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
