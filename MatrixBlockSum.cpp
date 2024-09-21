/*approach
  we first calculate prefixSum of the particular cell by taking count of its neighboring cells
  and with that we re arrange mat accordingly and finally return the mat itself*/
class Solution{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat,int k){
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>prefix(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int r1 = max(0,i-k), c1 = max(0,j-k);
                int r2 = min(n-1,i+k), c2 = min(m-1,j+k);
                mat[i][j] = prefix[r2+1][c2+1] - (r1>0 ? prefix[r1][c2+1] : 0) - (c1>0 ? prefix[r2+1][c1] : 0) + (r1>0 && c1>0 ? prefix[r1][c1] : 0);
            }
        }
        return mat;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
