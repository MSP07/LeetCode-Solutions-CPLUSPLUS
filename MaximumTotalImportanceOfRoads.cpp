/*approach
  we keep track of the degree of vertices and then we sort the vertices in
  descending order and we update the vertices as n-i from 0 to n. Then we add 
  up the sum of all the vertices and nodes*/
class Solution{
public:
    long long maximumImportance(int n,vector<vector<int>>& roads){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int> order(n,0);
        for(const auto&road:roads){
            order[road[0]]++;
            order[road[1]]++;
        }
        vector<pair<int,int>> cities;
        for(int i=0;i<n;++i){
            cities.push_back({order[i],i});
        }
        sort(cities.rbegin(),cities.rend());
        vector<int> values(n);
        for(int i=0;i<n;++i){
            values[cities[i].second] = n-i;
        }
        long long total_importance= 0;
        for(const auto&road:roads){
            total_importance += values[road[0]] + values[road[1]];
        }
        return total_importance;
    }
};
