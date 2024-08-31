/*approach
  we use priority queue and carefully take the elements in the diagonal
  and add them back to the matrix with top of priority queue as mat[i][j]
  and pop the pq and finally return the same matrix*/
class Solution{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>diagonal;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                diagonal[i-j].push(mat[i][j]);
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                mat[i][j] = diagonal[i-j].top();
                diagonal[i-j].pop();
            }
        }
        return mat;
    }
};
