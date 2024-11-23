/*approach
  matrix,simulation
  we simply follow the given rules and form the matrix*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int>ans;
        bool btu = true;
        int i=0,j=0;
        while(ans.size()<n*m){
            ans.push_back(mat[i][j]);
            if(btu){
                if(j==m-1){
                    i++;
                    btu = false;
                }else if(i==0){
                    j++;
                    btu = false;
                }else{
                    i--;
                    j++;
                }
            }else{
                if(i==n-1){
                    j++;
                    btu = true;
                }else if(j==0){
                    i++;
                    btu=true;
                }else{
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};
