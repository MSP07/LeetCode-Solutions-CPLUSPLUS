/*approach
  dp,sorting
  first we sort the given arrays so that we can find the first robot the nearest factory
  then we keep track of the robots movements and try out all possible ways and take the min
  of that, since given that there is a possibility another robot can follow the path of first robot
  and reach the same factory of the first robot we keep track and assign that val to the new robot
  reducing recurring subproblems and finally return the min one*/
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size();
        int m = factory.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
        dp[0][0] = 0;
        for (int j = 1; j <= m; ++j) {  
            dp[0][j] = 0;  
            for (int i = 1; i <= n; ++i) {  
                dp[i][j] = dp[i][j - 1];  
                long long distance_sum = 0;
                for (int count = 1; count <= min(factory[j - 1][1], i); ++count) {
                    distance_sum += abs(robot[i - count] - factory[j - 1][0]);
                    if (dp[i - count][j - 1] != LLONG_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i - count][j - 1] + distance_sum);
                    }
                }
            }
        }
        return dp[n][m]; 
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
