/*approach
  memoization
  we recursively see what happens if we take the element and not take the element and keep track
  of them. If we come across visited value we just return it*/
class Solution{
private:
    int helper(int index,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(index==0){
            if(amount%coins[index]==0)return amount/coins[index];
            else return 1e9;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        int notTake = 0 + helper(index-1,amount,coins,dp);
        int take = INT_MAX;
        if(coins[index]<=amount) take = 1 + helper(index,amount-coins[index],coins,dp);
        return dp[index][amount] = min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins,int amount){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = helper(n-1,amount,coins,dp);
        return (ans>=1e9) ? -1 : ans;
    }
};
