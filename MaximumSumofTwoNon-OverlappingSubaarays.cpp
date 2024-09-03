/*approach
  we calculate prefixSum and manipulate the data accordingly since given secondLen comes first
  with the help of that we first calculate maxFirstLen update our result then we calculate maxSecondLen
  with the help of firstLen and update our result and finally return the result*/
class Solution{
public:
    int maxSumTwoNoOverlap(vector<int>& nums,int firstLen,int secondLen){
        int n = nums.size();
        vector<int>prefixSum(n+1,0);
        for(int i=0;i<n;++i){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        int maxFirstLen = 0, maxSecondLen = 0, result = 0;
        for(int i=firstLen+secondLen;i<=n;++i){
            maxFirstLen = max(maxFirstLen,prefixSum[i-secondLen]-prefixSum[i-secondLen-firstLen]);
            result = max(result,maxFirstLen+(prefixSum[i]-prefixSum[i-secondLen]));

            maxSecondLen = max(maxSecondLen,prefixSum[i-firstLen]-prefixSum[i-firstLen-secondLen]);
            result = max(result,maxSecondLen+(prefixSum[i]-prefixSum[i-firstLen]));
        }
        return result;
    }
};
