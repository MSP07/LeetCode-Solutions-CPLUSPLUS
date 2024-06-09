//approach
//we keep a hashmap for prefix sum
//if we find the prefixsum%k in the hashmap we increase count that much
//else we set that prefix sum if that element to 1
//after complete iteration we return the cnt
class Solution{
public:
    int subarraysDivByK(vector<int>&nums,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int cnt = 0, prefixSum = 0;
        unordered_map<int,int>prefix;
        prefix[0]=1;
        for(int i=1;i<nums.size();i++){
            prefixSum += nums[i];
            int mod = prefixSum%k;
            if(mod<0){
                mod += k;
            }
            if(prefix.count(mod)){
                cnt += prefix[mod];
                prefix[mod]++;
            }else{
                prefix[mod]=1;
            }
        }
        return cnt;
    }
};
