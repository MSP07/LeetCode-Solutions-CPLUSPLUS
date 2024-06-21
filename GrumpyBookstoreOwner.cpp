/*aproach
  sliding window approach
  first we take the customer satsifaction and when the owner gets grumpy we add it
  when the minute(ith position) goes more than minutes and the owner was grumpy we remove that value
  we keep track of maximum value of this process and return that at the end*/
class Solution{
public:
    int maxSatisfied(vector<int>& customers,vector<int>& grumpy,int minutes){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = customers.size();
        int baseSatisfaction = 0;
        for(int i=0;i<n;++i){
            if(grumpy[i]==0) baseSatisfaction += customers[i];
        }
        int extraSatisfaction = 0;
        int maxExtraSatisfaction = 0;
        for(int i=0;i<n;++i){
            if(grumpy[i]==1){
                extraSatisfaction += customers[i];
            }
            if(i>=minutes && grumpy[i-minutes]==1){
                extraSatisfaction -= customers[i-minutes];
            }
            maxExtraSatisfaction = max(maxExtraSatisfaction,extraSatisfaction);
        }
        return maxExtraSatisfaction;
    }
};
