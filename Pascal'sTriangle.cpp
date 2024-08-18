/*approach
  dp
  we start from {1} and for every next num till we exhaust numRows
  we create row vector with i+1 space marking it all has 1's except the first and last
  we change each and everything by previous row elements like ans[i-1][j-1] summed up with
  next element ans[i-1][j] and after exhausting that row we add that row to our ans vector
  and finally return it*/
class Solution{
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=1;i<numRows;++i){
            vector<int>row(i+1,1);
            for(int j=1;j<i;++j){
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};
