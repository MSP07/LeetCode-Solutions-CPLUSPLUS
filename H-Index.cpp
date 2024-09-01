/*approach
  sort
  we sort the given citations, now we need a point from where on the next elements will be
  definitely greater since we have sorted the given array lets say 3 is the point then definitely
  the upcoming elements will have min 3 as it is sorted so we find that point by either 
  n-i <= citations[i] or citations[i] >= n-i and we return that n-i*/
class Solution{
public:
    int hIndex(vector<int>& citations){
        int n = citations.size();
        sort(citations.begin(),citations.end());
        for(int i=0;i<n;++i){
            if(citations[i]>=n-i){
                return n-i;
            }
        }
        return 0;
    }
};
