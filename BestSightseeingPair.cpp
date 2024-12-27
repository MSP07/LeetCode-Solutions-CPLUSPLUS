/*approach
  dp approach
  we intialise max answer to be values[0] + 0 as values[i] + i
  and we update the maxScore to maxVal + values[j] - j or maxScore 
  whichever is maximum. we keep on updating maxVal to max of maxVal
  or values[j] + j and finally return maxScore
  optimal approach
  instead of remembering index we can simply remember the value
  and calculate the max one and finally return it*/
class Solution{
public:
    int maxScoreSightseeingPair(vector<int>& values){
        //base approach
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int maxVal = values[0] + 0;
        int maxScore = 0;
        for(int j=1;j<values.size();++j){
            maxScore = max(maxScore,maxVal+values[j]-j);
            maxVal = max(maxVal,values[j]+j);
        }
        return maxScore;
        //optimal approach
        int a = values[0];
        int ans = 0;
        for(int i=1;i<values.size();i++){
            a--;
            ans = max(ans,a+values[i]);
            a = max(a,values[i]);
        }
        return ans;
    }
};
