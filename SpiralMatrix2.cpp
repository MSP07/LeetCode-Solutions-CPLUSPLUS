/*approach
  simulation
  we simply follow the given rules to fulfill the spiral matrix
  and finally return the matrix*/
class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int left = 0, top = 0;
        int right = n-1, bottom = n-1;
        int i = 1;
        while(top<=bottom && left<=right){
            for(int j=left;j<=right;++j){
                matrix[top][j] = i++;
            }
            top++;
            for(int j=top;j<=bottom;++j){
                matrix[j][right] = i++;
            }
            right--;
            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    matrix[bottom][j] = i++;
                }
                bottom--;
            }
            if(left<=right){
                for(int j=bottom;j>=top;j--){
                    matrix[j][left] = i++;
                }
                left++;
            }
        }
        return matrix;
    }
};
