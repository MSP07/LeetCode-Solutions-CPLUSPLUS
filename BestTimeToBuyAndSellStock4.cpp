/*approach
  space optimization
  we keep a var transNo indicating no of transactions
  for k=1 transNo will be 2 as buy + sell so with this logic we 
  iterate through the array from 0th element till last or till 2*k (as for k=1 transNo will be 2)
  we choose whichever is max whether buying on the current day or next upcoming days and similarly
  choose max on selling on this day or on upcoming days and finally return dp[0][0] or curr[0][0]
  as we iterate from 0 to n in memoization we do the reverse in tabulation and space optimization
  so the ans will be in dp[0][0] or curr[0]*/
class Solution{
private:
    int find(vector<int>& prices,int ind,int transNo,int n,int k,vector<vector<int>>& dp){
        if(ind==n || transNo == 2*k)return 0;
        if(dp[ind][transNo]!=-1)return dp[ind][transNo];
        if(transNo%2==0){
            return dp[ind][transNo] = max(-prices[ind] + find(prices,ind+1,transNo+1,n,k,dp), find(prices,ind+1,transNo,n,k,dp));
        }else{
            return dp[ind][transNo] = max(prices[ind] + find(prices,ind+1,transNo+1,n,k,dp), find(prices,ind+1,transNo,n,k,dp));
        }
    }
public:
    int maxProfit(vector<int>& prices,int k){
        int n = prices.size();
        vector<int>ahead(k+1,0);
        vector<int>curr(k+1,0);
        for(int ind=n-1;ind>=0;--ind){
            for(int transNo=2*k-1;transNo>=0;--transNo){
                if(transNo%2==0){
                    curr[transNo] = max(-prices[ind] + ahead[transNo+1], ahead[transNo]);
                }else{
                    curr[transNo] = max(prices[ind] + ahead[transNo+1], ahead[transNo]);
                }
            }
        }
        return curr[0];
    }
};
