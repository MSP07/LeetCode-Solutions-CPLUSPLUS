/*approach
  sliding window
  first we traverse through the array and mark the consecutive elements their length and if not we mark them 1
  agian we iterate through the array this time from index k-1 and if the element has a consecutive length >= k
  then that element is the highest one and we add that to our answer else we add -1 and finally return the result*/
class Solution{
public:
    vector<int>resultsArray(vector<int>& nums,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        vector<int>consec(n);
        consec[0] = 1;
        for(int i=1;i<n;++i){
            if(nums[i]==nums[i-1]+1){
                consec[i] = consec[i-1]+1;
            }else{
                consec[i] = 1;
            }
        }
        vector<int>results;
        for(int i=k-1;i<n;++i){
            if(consec[i]>=k){
                results.push_back(nums[i]);
            }else{
                results.push_back(-1);
            }
        }
        return results;
    }
};
