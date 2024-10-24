/*approach
  greedy
  we need the index from where we can complete the whole vector
  that to getting more gas than cost we do that by calculating gas
  cost along the way and calculating the sum of diff (gas[i]-cost[i])
  if this becomes <0 then out starting point is wrong so we update that
  and finally if the total gas is >= total cost then only we return the
  start point else we return -1*/
class Solution{
public:
    int canComplete(vector<int>& gas,vector<int>& cost){
        int n = cost.size();
        int totalCost = 0, totalGas = 0;
        int tank = 0, startPoint = 0;
        for(int i=0;i<n;++i){
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i]-cost[i];
            if(tank<0){
                startPoint = i+1;
                tank = 0;
            }
        }
        return totalGas >= totalCost ? startPoint : -1;
    }
};
