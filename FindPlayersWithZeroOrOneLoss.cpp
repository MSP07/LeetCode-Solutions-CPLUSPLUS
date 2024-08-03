/*approach
  we use hash map to store winner with 0 count
  and increase count of losers.
  then we iterate through the map(as it will be in sorted manner)
  and if loses is 0 we push it into noLoss array and if loses is 1
  we push it into oneLoss array and we return it as {noLoss,oneLoss}*/
class Solution{
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        map<int,int>lossCount;
        for(auto& match:matches){
            int winner = match[0];
            int loser = match[1];
            lossCount[winner];
            lossCount[loser]++;
        }
        vector<int>noLoses,oneLoss;
        for(auto& entry:lossCount){
            if(entry.second==0){
                noLoses.push_back(entry.first);
            }else if(entry.second==1){
                oneLoss.push_back(entry.first);
            }
        }
        return {noLoses,oneLoss};
    }
};
