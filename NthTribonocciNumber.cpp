/*approach
  dp
  we declare base cases dp[0],dp[1],dp[2] as 0,1,1
  and we sum up dp[i] as dp[i-1]+dp[i-2]+dp[i-2] and finally
  the answer we will return in dp[n]*/
class Solution {
    vector<int>dp;
private:
    int find(int n){
        if(dp[n]!=-1)return dp[n];
        if(n==0)return 0;
        if(n<=2)return 1;
        return dp[n] = find(n-1)+find(n-2)+find(n-3);
    }
public:
    int tribonacci(int n) {
        dp.resize(38,0);
        // return find(n);
        dp[0] = 0; dp[1] = 1; dp[2] = 1;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
};
