/*approach
  dp
  base cases 0 and 1 with 1 and 10 diff values
  then unique vals will be the first 9 numbers and the same will be available too
  the unique val will incr by avail times and curr vals diff numbers in range will be prev nums + curr unique nums
  then we decr availability then return the diff values of n*/
class Solution{
public:
    int countNumbersWithUniqueDigits(int n){
        if(n==0)return 1;
        if(n==1)return 10;
        vector<int>dp(n+1,0);
        dp[0] = 1;dp[1]=10;
        int unique = 9, avail = 9;
        for(int i=2;i<=n;++i){
            unique *= avail;
            dp[i] = dp[i-1] + unique;
            avail--;
        }
        return dp[n];
    }
};
