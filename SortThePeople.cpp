/*approach
  we simply use hashmap to store details of given names
  corresponding to the heights and we sort the heights
  in descending order and we change the names according
  to the sorted heights and return the names*/
class Solution{
public:
    vector<string> sortPeople(vector<string>& names,vector<int>& heights){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<int,string>lookup;
        for(int i=0;i<heights.size();++i){
            lookup[heights[i]] = names[i];
        }
        sort(names.rbegin(),names.rend());
        for(int i=0;i<names.size();++i){
            names[i] = lookup[heights[i]];
        }
        return names;
    }
};
