/*approach
  we first initailise how much ever sum is till kth index in given array and we 
  initialise maxsize to it and we manipulate the totalsum we calculated till kth index 
  accordingly and we take max between maxsize and totalsum and return it*/
class Solution{
public:
    int maxScore(vector<int>& cardPoints,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = cardPoints.size();
        int maxsize = 0, totalsum = 0;
        for(int i=0;i<k;++i){
            totalsum += cardPoints[i];
        }
        maxsize = totalsum;
        for(int i=0;i<k;++i){
            totalsum -= cardPoints[i-k-1];
            totalsum += cardPoints[n-1-i];

            maxsize = max(maxsize,totalsum);
        }
        return maxsize;
    }
};
