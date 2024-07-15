/*approach
  since there is a constraint that says only 2 transactions are allowed
  so we keep a var cnt that ensures this condition
  iterate from start till end calculate profit either if we can buy and by
  buying will there be more profit and calculate same for selling case too
  we either can buy/sell in a day and gain/loss some money or move to next index
  and sell/buy there and if we enounter ind==n || cnt==2 we simply return 0
  we tabulate the same and space optimise that too*/
class Solution{
private:
    int fn(vector<int>& prices,int n,int ind,int buy,int cnt,vector<vector<vector<int>>> &dp){
        if(ind==n || cnt==2)return 0;
        long profit = 0;
        if(buy){
            profit = max(-prices[ind],fn(prices,n,ind+1,0,cnt,dp),fn(prices,n,ind+1,1,cnt,dp));
        }else{
            profit = max(prices[ind] + fn(prices,n,ind+1,1,cnt-1,dp),fn(prices,n,ind+1,0,cnt,dp));
        }
        return dp[ind][buy][cnt] = profit;
    }
public:
    int maxProfit(vector<int>& prices){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = prices.size();
        if(n==1)return 0;
        //vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> ahead(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        for(int ind=n-1;ind>=0;--ind){
            for(int buy=0;buy<=1;++buy){
                for(int cnt=0;cnt<=2;++cnt){
                    if(buy){
                        curr[buy][cnt] = max(-prices[ind] + ahead[0][cnt] , ahead[1][cnt]);
                    }else{
                        curr[buy][cnt] = max(prices[ind] + ahead[1][cnt-1], ahead[0][cnt]);
                    }
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};
