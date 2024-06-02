//approach
//we iterate through only mat.size() as mat.size()==mat[0].size()
//we first add primary diagonal elements, then secondary diagonal elements
//then we subtract the n/2 element in matrix if n is odd
class Solution{
public:
    int diagonalSum(vector<vector<int>>& mat){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = mat.size();
        if(n==1)return mat[0][0];
        int diagSum = 0;
        for(int i=0;i<n;i++){
            diagSum += mat[i][i];
        }
        for(int i=0;i<n;i++){
            diagSum += mat[i][n-1-i]; 
        }
        if(n%2!=0)diagSum -= mat[n/2][n/2];
        return diagSum;
    }
};
