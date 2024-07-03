/*approach
  memoization
  we start from end and when at 0th index if amount is a multiple of the element at 0th index then we return 1
  if we encounter a rememebered path we return that value stored in that array*/
class Solution{
private:
    int fn(int ind,int amount,vector<int>& coins,vector<vector<long>>& dp){
        if(ind==0){
            return (amount%coins[ind]==0);
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        long notTake = fn(ind-1,amount,coins,dp);
        long take = 0;
        if(coins[ind]<=amount) take = fn(ind,amount-coins[ind],coins,dp);
        return notTake + take;
    }
public:
    int change(int amount,vector<int>& coins){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = coins.size();
        vector<vector<long>> dp(n,vector<long>(amount+1,-1));
        return fn(n-1,amount,coins,dp);
    }
};
