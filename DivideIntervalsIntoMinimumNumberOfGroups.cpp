/*approach
  sorting,greedy,hashmap
  if we look at the problem in another way we need to find the no of overlapping intervals because only then
  we have something to group else the whole input can be grouped into one. So we do that first we keep track of 
  all the intervals start point and end point with some high and low values then we sort the hashmap in order to find
  the overlapping intervals then we simply add the high and low vals while iterating the hashmap and keep track of the maxOne
  meaning the maximum group that can be formed which will be the min groups needed too*/
class Solution{
public:
    int minGroups(vector<vector<int>>& intervals){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<pair<int,int>>events;
        for(auto& interval:intervals){
            events.push_back({interval[0],1});
            events.push_back({interval[1]+1,-1});
        }
        sort(events.begin(),events.end());
        int active = 0, maxActive = 0;
        for(const auto& [time,type]:events){
            active += type;
            maxActive = max(maxActive,active);
        }
        return maxActive;
    }
};
