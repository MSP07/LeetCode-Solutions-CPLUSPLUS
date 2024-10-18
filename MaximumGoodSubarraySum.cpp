/*approach
  hashmap, prefixSum
  first we calculate the prefixSum of all elements then we use a hashmap to store indices 
  we iterate the array and find whether there are any elements in the array that has nums[i]+k or nums[i]-k
  using hashmap and if it does have we update the max ans with its sum using the prefixSum calculated and if the
  index we are currently in is not updated we update that too and finally return the ans if there is any subarray
  matching the given conditions else we return 0*/
class Solution{
public:
    long long maximumSubarraySum(vector<int>& nums,int k){
        int n = nums.size();
        long long ans = LLONG_MIN;
        vector<long long>prefixSum(n+1);
        prefixSum[0] = 0;
        for(int i=1;i<=n;++i){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        unordered_map<int,int>hashi;
        for(int i=0;i<n;++i){
            if(hashi.find(nums[i]-k)!=hashi.end()){
                ans = max(ans,prefixSum[i+1]-prefixSum[hashi[nums[i]-k]]);
            }
            if(hashi.find(nums[i]+k)!=hashi.end()){
                ans = max(ans,prefixSum[i+1]-prefixSum[hashi[nums[i]+k]]);
            }
            if(hashi.find(nums[i])!=hashi.end()){
                if(prefixSum[i]-prefixSum[hashi[nums[i]]]<=0)
                hashi[nums[i]] = i;
            }
            else hashi[nums[i]] = i;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
