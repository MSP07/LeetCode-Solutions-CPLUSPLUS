/*approach
  sorting
  sort the given array so we can identify duplicates
  start from second element and check if the curr element 
  is greater than the prev one if yes then we incr the count
  and finally return the count*/
class Solution{
public:
    int distributeCandies(vector<int>& candyType){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        sort(candyType.begin(),candyType.end());
        int count = 1;
        for(int i=1;i<candyType.size();++i){
            if(count>=candyType.size()/2)break;
            if(candyType[i]>candyType[i-1]){
                ++count;
            }
        }
        return count;
    }
};
