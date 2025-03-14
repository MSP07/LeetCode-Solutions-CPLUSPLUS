/*approach
  binary search
  we start with highest and lowest elements as right and left
  and we calculate mid if the mid can be divided we calculate that by
  dividing all the candies by mid and adding them up if that division sum
  is greater than k then it is possible to divide it to k children and hence
  we return true else false if true we now know that the left side till mid
  is possible to be divided so we shift our focus to right part i.e mid+1 to right
  if it is not true then we shift our focus to left to mid-1 and finally return right as due to opp polarity our ans will be right*/
class Solution {
private:
    bool canAllocateCandies(vector<int>& candies, long long k,int numOfCandies){
        long long int maxNumOfChildren = 0;
        for(int pileIndex = 0;pileIndex < candies.size();pileIndex++){
            maxNumOfChildren += candies[pileIndex]/numOfCandies;  
        }
        return maxNumOfChildren >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int maxCandiesInPile = 0;
        for(int i = 0;i<candies.size();i++){
            maxCandiesInPile = max(maxCandiesInPile, candies[i]);
        }
        int left = 0, right = maxCandiesInPile;
        while(left < right){
            int middle = (left + right + 1) / 2;
            if(canAllocateCandies(candies, k, middle)){
                left = middle;
            }else{
                right = middle - 1;
            }
        }
        return left;
    }
};
