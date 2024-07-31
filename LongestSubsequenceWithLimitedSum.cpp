/*approach
  greedy
  we sort the given number for convinence and we make a prefixSum array
  then we make ans array and iterate through queries array with, query[i] 
  as target. we run another loop inside to check for prefixSum <= target
  if it is we increase maxLength by 1. when the prefixSum exceeds target 
  we berak and update the ans array as ans[i] = maxLength and finally return ans
  NOTE: instead of running another loop we can simply find upperbound w.r.t target and
  subtract preixSum.begin()-1 from it but in this case prefixSum will be calculated like
  for(int i=0;i<n;++i) prefixSum[i] = nums[i] + prefixSum[i+1] and prefixSum will be
  declared as vector<int>prefixSum(nums.size()+1,0) and simply we will update that 
  upperbound as maxlength and ans[i] = maxlength and return ans*/
class Solution{
public:
    vector<int> answerQueries(vector<int>& nums,vector<int>& queries){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        sort(nums.begin(),nums.end());
        vector<int>prefixSum(nums.size());
        prefixSum[0] = nums[0];
        for(int i=1;i<nums.size();++i){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();++i){
            int target  = queries[i];
            int maxLength = 0;
            for(int j=0;j<queries.size();++j){
                if(prefixSum[j]<=target){
                    maxLength++;
                }else{
                    break;
                }
            }
            ans[i] = maxLength;
        }
        return ans;
    }
