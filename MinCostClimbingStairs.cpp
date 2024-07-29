/*appraoch
  dp - tabulation
  simply choose min of previous two with sum of dp array
  finally return last element of dp array*/
class Solution{
public:
    int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();
        if(n==1)return cost[0];
        if(n==2)return min(cost[0],cost[1]);
        if(n==3)return min(cost[1],cost[0]+cost[2]);
        vector<int>dp(n+1,0);
        for(int i=2;i<=n;++i){
            dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};
