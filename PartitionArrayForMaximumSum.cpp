/*approach
  dp approach
  we start from first element and we go on to form diff
  partitions till i+k or n whichever comes first. we keep track of max
  element till then and for each partition we calculate sum which will be
  len * max element till that partition and the next partition sum which will
  be fn(i+1,....) and in that we keep track of which partition gives us the 
  maximum sum and return it. we memoize and tabulate this*/
class Solution{
private:
    int fn(int i,vector<int>& arr,int k,vector<int>& dp){
        int n = arr.size();
        if(i==arr.size())return 0;
        int maxAns = INT_MIN;
        int maxi = INT_MIN, len = 0;
        for(int j=i;j<min(n,i+k);++j){
            ++len;
            maxi = max(maxi,arr[j]);
            int sum = len*maxi + fn(j+1,arr,k,dp);
            maxAns = max(maxAns,sum);
        }
        return dp[i] = maxAns;
    }
public: 
    int maxSumAfterParttioning(vector<int>& arr,int k){
        vector<int>dp(arr.size()+1,0);
        int n = arr.size();
        dp[n] = 0;
        for(int i=arr.size()-1;i>=0;--i){
            int maxAns = INT_MIN;
            int maxi = INT_MIN, len = 0;
            for(int j=i;j<min(n,i+k);++j){
                ++len;
                maxi = max(maxi,arr[j]);
                int sum = len*maxi + dp[j+1];
                maxAns = max(maxAns,sum);
            }
            dp[i] = maxAns;
        }
        return dp[0];
    }
};
