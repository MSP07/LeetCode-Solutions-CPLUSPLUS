/*approach
  dp approach
  we take values from prev row same column and prev row prev column add them and 
  push them to answer and finally return the rowIndex row in the pascal's triangle*/
class Solution{
public:
    vector<int> getRow(int rowIndex){
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=1;i<=rowIndex;++i){
            vector<int>row(i+1,1);
            for(int j=1;i<i;++j){
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(row);
        }
        return ans[rowIndex];
    }
};
