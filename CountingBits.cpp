/*approach
  dp
  to do this in 0(n) we simply iterate while checking if the num in nums
  when doubled comes out to its index then we update the variable to index
  update the dp table and finally return the dp*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        int temp = 1;
        for(int i=1;i<=n;i++){
            if(temp*2==i){
                temp = i;
            }
            dp[i] = dp[i-temp] + 1;
        }
        return dp;
    }
};
