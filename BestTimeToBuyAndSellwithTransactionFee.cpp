/*appraoch
  we iterate through the given array and while buying we just subtract the fee from it
  and we choose max of buying at current index and buying in other indices. while selling
  we simply sell and add the val or choose other indices whichever is max since we are already
  subtracting the fee while buying and we return the max as profit.
  We tabulate the space optmize the same*/
class Solution{
private:
    int fn(vector<int>& prices,int ind,int buy,int n,int fee,vector<vector<long long>> &dp){
        if(ind==n)return 0;
        //memoization
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        long long profit;
        if(buy){
            profit = max(-prices[ind] - fee + fn(prices,ind+1,0,n,fee,dp), fn(prices,ind+1,1,n,fee,dp));
        }else{
            profit = max(prices[ind] + fn(prices,ind+1,1,n,fee,dp), fn(prices,ind+1,0,n,fee,dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices,int fee){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = prices.size();
        vector<vector<long long>> dp(n+1,vector<long long>(2,0));
        //tabulation
        for(int ind=n-1;ind>=0;--ind){
            dp[ind][1] = max(-prices[ind] - fee + dp[ind+1][0], dp[ind+1][1]);
            dp[ind][0] = max(prices[ind] + dp[ind+1][1], dp[ind+1][0]);
        }
        return dp[0][1];
        //space optimization
        vector<long long>ahead(2,0);
        vector<long long>curr(2,0);
        for(int ind=n-1;ind>=0;--ind){
            curr[1] = max(-prices[ind] - fee + ahead[0], ahead[1]);
            curr[0] = max(prices[ind] + ahead[1], ahead[0]);
            ahead = curr;
        }
        return curr[1];
    }
};
