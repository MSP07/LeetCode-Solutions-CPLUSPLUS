/*approach
  dp approach
  for binary tree to be made we start from one node and iteratively add two nodes(if possible) one will be with i-1 val 
  and another one with n-i value we recursively call the fn and if n becomes less than 1 we return only one node is possible
  since there are overlapping subproblems we use memoization and return the ans*/
class Solution{
    int dp[20]{};
public:
    int numTrees(int n){
        if(dp[n])return dp[n];
        if(n<=1)return 1;
        for(int i=1;i<=n;++i){
            dp[n] += numTrees(i-1)*numTrees(n-i);
        }
        return dp[n];
    }
};
