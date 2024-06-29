/*approach
  we keep track of the parent of given nodes and mark them visited
  finally we sort them w.r.t the nodes*/
class Solution{
private:
    void dfs(vector<vector<int>>& graph,int parent,int curr,vector<vector<int>>& nodes,vector<bool>& visited){
        visited[curr] = 1;
        for(auto it:graph[curr]){
            if(!visited[it]){
                nodes[it].push_back(parent);
                dfs(graph,parent,it,nodes,visited);
            }
        }
    }
public:
    vector<vector<int>> getAllAncestors(int n,vector<vector<int>>& edges){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<int>> graph(n);
        vector<vector<int>> nodes(n);
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
        }
        for(int i=0;i<n;++i){
            vector<bool> visited(n,0);
            dfs(graph,i,i,nodes,visited);
        }
        for(int i=0;i<n;++i){
            sort(nodes[i].begin(),nodes[i].end());
        }
        return nodes;
    }
};
