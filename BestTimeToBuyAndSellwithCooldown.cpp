/*approach
  we start from first index iterate till last. We either choose the current element to buy
  and move forward with buy=0 or move forward with buy=1 whichever is max. we make change on 
  selling if we decide to sell on current index then prices[ind] + while calling the fn again
  we make sure ind is increased by 2 since one day is cooldown and make buy as 1 as we sold the 
  old stock else we call the fn for next index with buy as 0 as we have not sold it yet and we return
  the max of that. we tabulate and space optimise this*/
class Solution{
private:
    int fn(vector<int>& prices,int ind,int buy,int n,vector<vector<int>> &dp){
        if(ind>=n)return 0;
        //memoization
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        long profit;
        if(buy){
            profit = max(-prices[ind] + fn(prices,ind+1,0,n,dp), fn(prices,ind+1,1,n,dp));
        }else{
            profit = max(prices[ind] + fn(prices,ind+2,1,n,dp), fn(prices,ind+1,0,n,dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        //tabulation
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int ind=n-1;ind>=0;--ind){
            dp[ind][1] = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
            dp[ind][0] = max(prices[ind] + (ind+2>=n ? dp[ind+2][1] : 0), dp[ind+1][0]);
        }
        return dp[0][1];
        //space optimization
        vector<int>curr(2,0);
        vector<int>front1(2,0);
        vector<int>front2(2,0);
        for(int ind=n-1;ind>=0;--ind){
            curr[1] = max(-prices[ind] + front1[0], front1[1]);
            curr[0] = max(prices[ind] + (ind+2>=n ? front2[1] : 0), front1[0]);
        }
        return curr[1];
    }
};
