/*approach
  bfs,bitmask approach
  using bfs we traverse through all the nodes and mark them visited
  we use bitmask to check whether the node as come to an end else it will be an infinite loop
  if we complete the full node traversal we return length else we return -1*/
class Solution{
public:
    int shortestPathLength(vector<vector<int>>& graph){
        int n = graph.size();
        if(n==1)return 0;
        queue<tuple<int,int,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        for(int i=0;i<n;++i){
            q.push({i,1<<i,0});
            visited[i][1<<i] = true;
        }
        while(!q.empty()){
            auto [node,mask,length] = q.front();
            q.pop();

            if(mask == (1<<n)-1){
                return length;
            }
            for(int neighbor:graph[node]){
                int new_mask = mask | (1<<neighbor);
                if(!visited[neighbor][new_mask]){
                    q.push({neighbor,new_mask,length+1});
                    visited[neighbor][new_mask]=true;
                }
            }
        }
        return -1;
    }
};
