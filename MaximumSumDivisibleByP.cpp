/*approach
  hashmap, prefixSum
  our goal is to find and reduce the remainder when totalSum is divided by p(if it exists)
  we use a hashmap to keep track of prefixSum of various subarrays and their remainders with p
  oru target remainder will be current remainder - totalRemainder + p % p with this we also find 
  for a way where diff prefixSums(continuous) can sum up and provide the answer, we cumulatively
  update the minLength or the answer*/
class Solution{
public:
    int minSubarray(vector<int>& nums,int p){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        long long totalSum = 0;
        for(int num:nums){
            totalSum += num;
        }
        int rem = totalSum % p;
        unordered_map<int,int>prefixMod;
        prefixMod[0] = -1;
        long long prefixSum = 0;
        int minLen = n;
        for(int i=0;i<n;++i){
            prefixSum += nums[i];
            int currMod = prefixSum % p;
            int targetMod = (currMod - rem + p) % p;
            if(prefixMod.find(targetMod)!=prefixMod.end()){
                minLen = min(minLen,i-prefixMod[targetMod]);
            }
            prefixMod[currMod] = i;
        }
        return minLen == n ? -1 : minLen;
    }
};
