/*approach
  prefixSum
  first we calculate whether consec elements are of same parity and store them in a vector
  then we calculate their prefixSum we do this so as to check for parity in start and end
  elements then while iterating in the queries for every query we take from,to and calculate
  their diff in parities if their diff is 0 then they are of diff parities else with same
  parities so we append true or false accordingly and finally return the ans vector*/
class Solution{
public:
    vector<bool> isArraySpecial(vector<int>& nums,vector<vector<int>>& queries){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = queries.size();
        vector<int>parity(n-1,0);
        for(int i=0;i<n-1;i++){
            parity[i] = (nums[i]%2 == nums[i+1]%2) ? 1 : 0;
        }
        vector<int>prefixSum(n,0);
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + parity[i-1];
        }
        vector<bool>ans;
        for(auto& query:queries){
            int from = query[0], to=query[1];
            if(from==to){
                ans.push_back(true);
            }else{
                int temp = prefixSum[to]-prefixSum[from];
                ans.push_back(temp==0);
            }
        }
        return ans;
    }
};
