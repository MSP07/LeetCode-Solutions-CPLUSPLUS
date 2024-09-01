/*approach
  prefixsum
  we first iterate and gather all indices prefix sum and calculate the total also at the same time
  now given to find abs(leftavg - rightavg) with some conditions. leftavg of ith element is nothing but the
  prefixsum[i]/(i+1) at that element and rightmax is nothing but totalsum - prefixsum[i] / (n-i-1) we carefully
  calculate rightavg as if i is in last index then rightavg is 0 then we calculate the curravg with this for each
  index and if it is less than prev avg then we update the avg and index and finally return the index*/
class Solution{
public:
    int minimumAverageDistance(vector<int>& nums){
        ios_base::sync_with_stdio();
        cin.tie(0);
        int n = nums.size();
        if(n==1)return 0;
        vector<long long>prefixSum(n,0);
        long long sum = 0;
        for(int i=0;i<n;++i){
            sum += nums[i];
            prefixSum[i] = sum;
        }
        int minAvg = INT_MAX;
        int minIndex = 0;
        for(int i=0;i<n;++i){
            long long leftAvg = prefixSum[i]/(i+1);
            long long rightAvg = (i==n-1) ? 0 : (sum-prefixSum[i])/(n-i-1);
            int currAvg = abs(leftAvg-rightAvg);
            if(currAvg < minAvg){
                minAvg = currAvg;
                minIndex = i;
            }
        }
        return minIndex;
    }
};
