/*approach
  topological sort, bfs
  first we calculate the degree of each node and create adjList of the graph
  then till we get to the final 2 nodes we take out the nodes and decrease their degree
  and decrease the node count by no of nodes in that degree in bfs level then we iterate in the neighborhood of that node using adjList
  then reduce their degree too as we have used them now and if their degree is 1 after reducing we push them into bfs too and finally
  the left out nodes (1 or 2) are the answer*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(n==1)return {0};
        vector<vector<int>>graph(n);
        vector<int>degree(n,0);
        for(auto& edge:edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;++i){
            if(degree[i]==1){
                q.push(i);
            }
        }
        int remainingNodes = n;
        while(remainingNodes>2){
            int leafSize = q.size();
            remainingNodes -= leafSize;
            for(int i=0;i<leafSize;++i){
                int leaf = q.front();
                q.pop();
                for(int neighbor:graph[leaf]){
                    degree[neighbor]--;
                    if(degree[neighbor]==1){
                        q.push(neighbor);
                    }
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
