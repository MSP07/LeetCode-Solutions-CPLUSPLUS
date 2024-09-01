/*approach
  we first check whether the dimensions match if not we return empty vector
  if they do match we change the original vector to matrix by adding ans[i]
  as original + i*n till original + i*n+n and we keep iterating till m and
  finally return the ans*/
class Solution{
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m,int n){
        vector<vector<int>>ans(m);
        int i;
        switch(m*n == original.size() ? 1 : 0){
            case 1:
                i=0;
                while(i<m){
                    ans[i] = vector<int>(original.begin()+i*n,original.begin()+(i*n+n));
                    ++i;
                }
                break;
            default:
                return {};
        }
        return ans;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
