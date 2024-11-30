/*approach
  in the question they have described to construct a eulerian path 
  to solve this problem we can use hierholzer's algorithm where we find
  the node that has outdegree - indegree = 1 that will be our first node
  and from that we construct our path and return the ans*/
class Solution{
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs){
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>outdegree,indegree;
        int startNode = pairs[0][0];
        for(auto pair:pairs){
            adj[pair[0]].push_back(pair[1]);
            outdegree[pair[0]]++;
            indegree[pair[1]]++;
        }
        for(auto[node,degree]:outdegree){
            if(outdegree[node]-indegree[node]==1){
                startNode = node;
                break;
            }
        }
        vector<int>stack;
        vector<vector<int>> result;
        stack.push_back(startNode);
        while (!stack.empty()) {
            int node = stack.back();
            if (!adj[node].empty()){
                int next = adj[node].back();
                adj[node].pop_back();
                stack.push_back(next);
            }else{
                stack.pop_back();
                if (!stack.empty()){
                    result.push_back({stack.back(), node});
                }
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
