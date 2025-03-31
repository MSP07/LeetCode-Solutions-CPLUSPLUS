/*approach
  sorting
  first we take all the adj count and store it in an array
  then we sort that all the max min combination is only possible in this array
  after that the sum of first k-1 elements is the min sum overall and sum from 
  last k-1 elements is the max sum overall and we return the diff between them*/
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k==1)return 0;
        vector<int>sums;
        for(int i=0;i<weights.size()-1;i++){
            sums.push_back(weights[i]+weights[i+1]);
        }
        sort(sums.begin(),sums.end());
        long long mini = accumulate(sums.begin(),sums.begin()+(k-1),0LL);
        long long maxi = accumulate(sums.end()-(k-1),sums.end(),0LL);
        return maxi-mini;
    }
};
