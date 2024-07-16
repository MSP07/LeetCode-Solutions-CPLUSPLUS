/*approach
  bfs approach
  keep a vector initialise all elements to int max
  then push the given node into queue with 0 marking
  it takes 0 moves to reach k. before pushing create a
  adj list and in queue iterate with the adj[node] if the 
  time taken by prev node and time by this adj node combined
  is less than any previous val stored in ans[nextnode] then update
  it. finally after full iteration if the max element in the ans is
  int max then return -1 as one node is not reached else return the 
  max value in the ans*/
class Solution{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<pair<int,int>>> adj(n+1);
        queue<pair<int,int>>q;
        vector<int>ans(n+1,INT_MAX);
        ans[k] = 0;
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        q.push({k,0});
        while(!q.empty()){
            auto [node,time] = q.front();
            q.pop();

            for(auto it:adj[node]){
                int nextnode = it.first;
                int weight = it.second;
                if(time+weight<ans[nextnode]){
                    ans[nextnode] = time+weight;
                    q.push({nextnode,time+weight});
                }
            }
        }
        int maxel = *max_element(ans.begin(),ans.end());
        return maxel== INT_MAX ? -1 : maxel;
    }
};
