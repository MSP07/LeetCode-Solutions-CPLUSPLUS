/*approach
  greedy appraoch
  we sort the given array since there is no direct
  causes in doing so and after sorting if the lowest/first 
  element is higher than the coins we have we return 0
  else we traverse the array and if coins become 0 we break
  or else we increase cnt and remove the particular element's value 
  from coins*/
class Solution{
public:
    int maxIceCream(vector<int>& costs,int coins){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int cnt = 0;
        sort(costs.begin(),costs.end());
        if(costs[0]>coins)return 0;
        for(int i=0;i<costs.size();++i){
            if(costs[i]<=coins){
                if(coins==0)break;
                ++cnt;
                coins -= costs[i];
            }
        }
        return cnt;
    }
};
