/*approach
  space optimisation
  basic approach is to traverse through array from index 0
  if we can buy (if we have not bought before) we will sell it in
  future so we take it as -prices[ind] and make the buy value 0 indicating
  we cant buy in future till we sell it, either we can buy and do this and move
  forward else we can keep buy as 1 and move and choose other element. for selling
  it is opp as we sell we add its value and make buy value 1. when we exhaust we return 0
  we tabulate this and space optimise this*/
class Solution{
// private:
//     long fn(int ind,int buy,vector<int>& prices,int n,vector<vector<long>> &dp){
//         if(ind==0)return 0;
//         long profit = 0;
//         if(dp[ind][buy]!=-1)return dp[ind][buy];
//         if(buy){
//             profit = max(-prices[ind] + fn(ind+1,0,prices,n,dp) , fn(ind+1,1,prices,n,dp) );
//         }else{
//             profit = max(prices[ind] + fn(ind+1,1,prices,n,dp) , fn(ind+1,0,prices,n,dp));
//         }
//         return dp[ind][buy] = profit;
//     }
public:
    int maxProfit(vector<int>& prices){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = prices.size();
        vector<long>ahead(2,0), curr(2,0);
        for(int ind=n-1;ind>=0;--ind){
            for(int buy=0;buy<=1;++buy){
                long profit = 0;
                if(buy){
                    profit = max(-prices[ind] + ahead[0] , ahead[1]);
                }else{
                    profit = max(prices[ind] + ahead[1] , ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};
