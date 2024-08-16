/*approach
  dp approach
  we intialise max answer to be values[0] + 0 as values[i] + i
  and we update the maxScore to maxVal + values[j] - j or maxScore 
  whichever is maximum. we keep on updating maxVal to max of maxVal
  or values[j] + j and finally return maxScore*/
class Solution{
public:
    int maxScoreSightseeingPair(vector<int>& values){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int maxVal = values[0] + 0;
        int maxScore = 0;
        for(int j=1;j<values.size();++j){
            maxScore = max(maxScore,maxVal+values[j]-j);
            maxVal = max(maxVal,values[j]+j);
        }
        return maxScore;
    }
};
