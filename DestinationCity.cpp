/*approach
  string, hashmap
  destination city or the final destination city will not be in
  the starting city so we use a hashmap to store all the starting 
  cities and iterate through paths and if we not find any destination
  city in the hashmap that is our answer*/
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>hashi;
        for(auto path:paths){
            hashi.insert(path[0]);
        }
        for(auto path:paths){
            if(hashi.find(path[1])==hashi.end()){
                return path[1];
            }
        }
        return "";
    }
};
