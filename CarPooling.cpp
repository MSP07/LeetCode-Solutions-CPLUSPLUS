/*approach
  we start by calculating the max destination that needs to be travelled
  then we declare an array to keep track of passengers with the maxLocation + 1 size
  then we iterate through trips again and update at trip[1](start) we take in trip[0] passengers
  and in trip[2](dest) we drop same trip[0] passengers and then we iterate through this array to
  calculate the total passengers and at any moment passengers if greater than capacity we return false
  else we return true*/
class Solution{
public: 
    bool carPooling(vector<vector<int>>& trips,int capacity){
        int maxLocation = 0;
        for(const auto& trip:trips){
            maxLocation = max(maxLocation,trip[2]);
        }
        vector<int>changes(maxLocation+1,0);
        for(const auto& trip : trips){
            changes[trip[1]] += trip[0];
            changes[trip[2]] -= trip[0];
        }
        int passengers = 0;
        for(int i=0;i<=maxLocation;++i){
            passengers += changes[i];
            if(passengers > capacity){
                return false;
            }
        }
        return true;
    }
};
