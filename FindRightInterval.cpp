/*approach
  sorting,binary search
  goal is to find index of particular element with given condition similar to finding lower bound
  first we take note of all starting points with their indices and sort them so we get the first starting point
  with its index, next for each element's end we find lower bound in the sorted array the will be its interval
  then if the found lower_bound is not in the last then we point that's index as curr element's right interval index
  and finally return the array filled with right interval index and return it*/
class Solution{
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = intervals.size();
        vector<pair<int,int>>starts;
        for(int i=0;i<n;++i){
            starts.push_back({intervals[i][0],i});
        }
        sort(starts.begin(),starts.end());
        vector<int>result(n,-1);
        for(int i=0;i<n;++i){
            int end = intervals[i][1];
            auto it = lower_bound(starts.begin(),starts.end(),make_pair(end,0));
            if(it!=starts.end()){
                result[i] = it->second;
            }
        }
        return result;
    }
};
