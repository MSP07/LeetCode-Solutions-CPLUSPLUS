/*approach
  bfs
  goal is simple any given edges the edge length will be max edge[i]+1 so we set that using bfs
  take the min distance reached with above condition to reach last node and return the distance array*/
class Solution{
private:
    vector<int> bfs(int n,vector<vector<int>>& adj){
        vector<int>temp(n,INT_MAX);
        temp[0] = 0;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int neighbor:adj[node]){
                if(temp[neighbor] > temp[node]+1){
                    temp[neighbor] = temp[node]+1;
                    q.push(neighbor);
                }
            }
        }
        return temp;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n,vector<vector<int>>& queries){
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int>ans;
        vector<int>dist(n,INT_MAX);
        dist[0] = 0;
        for(auto& query:queries){
            adj[query[0]].push_back(query[1]);
            dist = bfs(n,adj);
            ans.push_back(dist[n-1]==INT_MAX ? INT_MAX : dist[n-1]);
        }
        return ans;
    }
};
