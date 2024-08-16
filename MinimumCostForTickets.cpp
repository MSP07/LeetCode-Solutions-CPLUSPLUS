/*appraoch
  dp approach
  we start from first index and we have 3 possible costs 
  for 1 day, 7 days and 30 day. if we calculate for one day we take
  costs[0] and sum it with cost from next ind for 7 days we take costs[1]
  and sum of remaining part of tarvel if we take ind = 1 since we took for 7 days
  we will calculate remaining from ind = 8 (1+7) similarly for 30 days we take
  costs[2] and remainig part of vector and we finally return the min of all three
  we memoize and tabulate this*/
class Solution{
private:
    int fn(int dayInd,vector<int>& days,vector<int>& costs,vector<int>& dp){
        int n = days.size();
        if(dayInd >= n)return 0;

        if(dp[dayInd] != -1)return dp[dayInd];

        int cost1 = costs[0] + fn(dayInd+1,days,costs,dp);

        int i = dayInd;
        while(i<n && days[i] < days[dayInd]+7)++i;
        int cost2 = costs[1] + fn(i,days,costs,dp);

        i = dayInd;
        while(i<n && days[i] < days[dayInd]+30)++i;
        int cost3 = costs[2] + fn(i,days,costs,dp);

        return dp[dayInd] = min({cost1,cost2,cost3});
    }
public:
    int minCostTickets(vector<int>& days,vector<int>& costs){
        vector<int>dp(days.size()+1,0);
        int n = days.size();
        for(int dayInd = days.size()-1;dayInd>=0;--dayInd){
            int cost1 = costs[0] + dp[dayInd+1];

            int i = dayInd;
            while(i<n && days[i] < days[dayInd]+7)++i;
            int cost2 = costs[1] + dp[i];

            i = dayInd;
            while(i<n && days[i] < days[dayInd]+30)++i;
            int cost3 = costs[2] + dp[i];

            dp[dayInd] = min({cost1,cost2,cost3});
        }
        return dp[0];
    }
};
