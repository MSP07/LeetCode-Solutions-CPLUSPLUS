/*approach
  simulation
  we just follow the steps to make the given matrix its transpose
  by interchanging rows and cols and allotting values in their transpose
  matrix places*/
class Solution{
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix){
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>>transpose(col,vector<int>(row,0));
        for(int i=0;i<col;++i){
            for(int j=0;j<row;j++){
                transpose[i][j] = matrix[j][i];
            }
        }
        return transpose;
    }
};
