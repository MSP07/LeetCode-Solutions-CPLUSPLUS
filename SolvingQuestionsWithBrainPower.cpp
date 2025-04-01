/*approach
  dp, tabulation
  we will use take notTake method here we try out all possible
  combos either we take the current element and brainpower and skip the next
  brainpower elements taking curr [i][0] else we skip and go to next element
  and finally return the max of take and notTake*/
class Solution {
    vector<long long>dp;
private:
    long long find(int i,vector<vector<int>>& questions){
        if(i>=questions.size())return 0;
        if(dp[i]!=-1)return dp[i];
        long long notTake = find(i+1,questions);
        int next = i + questions[i][1]+1;
        long long take = questions[i][0] + find(next,questions);
        return dp[i] = max(take,notTake);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.resize(n+1,0);
        for(int i=n-1;i>=0;i--){
            long long notTake = dp[i+1];
            int next = i + questions[i][1] + 1;
            long long take = questions[i][0] + (next > n ? 0 : dp[next]);
            dp[i] = max(take,notTake);
        }
        return dp[0];
        // return find(0,questions);
    }
};
