/*approach
  simple iteration
  we keep track of min element encountered so far and we initialise
  mini element to the first element. profit will be current day value
  minus the mini day value. so we keep track of the max value we got as
  profit and finally after iteration we return that value*/
class Solution{
public:
    int maxProfit(vector<int>& prices){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int sum = 0;
        int mini = prices[0];
        for(int i=1;i<prices.size();++i){
            int profit = prices[i] - mini;
            sum = max(sum,profit);
            mini = min(mini,prices[i]);
        }
        return sum;
    }
};
