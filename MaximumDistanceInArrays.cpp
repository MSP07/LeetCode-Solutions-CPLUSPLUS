/*approach
  greedy
  we start by initialising arrays[0].back() as maxval and arrays[0].front() as min
  and while iterating through the array we update maxdistance by arrays[i].back()-minval
  or maxdistance whichever is max and arrays[i].front()-maxval or maxdistance whichever is max
  then we update minval and maxval till end of array which gives us 0(n) time complexity*/
class Solution{
public:
    int maxDistance(vector<vector<int>>& arrays){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int maxVal = arrays[0].back();
        int minVal = arrays[0].front();
        int maxDistance = 0;
        for(int i=1;i<arrays.size();++i){
            maxDistance = max(maxDistance, abs(arrays[i].back()-minVal));
            maxDistance = max(maxDistance, abs(maxVal - arrays[i].front()));

            minVal = min(minVal,arrays[i].front());
            maxVal = max(maxVal,arrays[i].back());
        }
        return maxDistance;
    }
};
