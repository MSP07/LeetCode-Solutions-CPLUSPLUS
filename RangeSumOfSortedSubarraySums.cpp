/*approach
  we create an array with subarray sums
  then we sort that array
  then we iterate on that array as given is 1 based indexing
  we make it 0 based by i = left - 1 and we iterate till right
  and we add the answer while performing % mod and we return it*/
class Solution{
public:
    int rangeSum(vector<int>& nums,int n,int left,int right){
        int mod = 1e9+7;
        vector<int> subarraySums;
        for(int i=0;i<n;i++){
            int currentSum = 0;
            for(int j=i;j<n;++j){
                currentSum += nums[j];
                subarraySums.push_back(currentSum);
            }
        }
        long long sum = 0;
        sort(subarraySums.begin(),subarraySums.end());
        for(int i=left-1;i<right;++i){
            sum = (sum+subarraySums[i])%mod;
        }
        return sum;
    }
};
