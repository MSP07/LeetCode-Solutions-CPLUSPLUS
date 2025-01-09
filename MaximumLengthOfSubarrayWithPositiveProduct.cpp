/*approach
  dp, greedy
  aim to calcualte highest len of nums that with
  product gives positive val and to do that we can iterate 
  and count the negatives and positives if we encounter positives we simply increase the count
  and increase the count of negatives if there are prev negatives as negatives*positives is negatives
  when we encounter negatives we swap the count in positives and negatives as again even negatives lead to positive
  and that can be handled if swapped and if we come across 0 we reset the count of positive and negative to 0
  keep track the max of positives and return them finally*/
class Solution{
public:
    int getMaxLen(vector<int>& nums){
        int negative = 0, positive = 0, maxLen = 0;
        for(int num:nums){
            if(num>0){
                positive++;
                negative = (negative>0) ? negative+1 : 0;
            }else if(num<0){
                int temp = positive;
                positive = (negative>0) ? negative+1 : 0;
            }else{
                negative = 0;
                positive = 0;
            }
            maxLen = max(maxLen,positive);
        }
        return maxLen;
    }
};
