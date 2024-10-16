/*approach
  priority queue, dp
  we should explore all ways and choose the one with min cost and also that comes under maxTime
  to achieve both of this we can use priority queue to make sure the min elements are always at the top
  we start by creating adjlist then declaring a vector to keep track of minTime and minTime[0] = 0
  we start from first node then iterate through adj[city] to see where we can reach from first node
  and calculate the cost it takes to reach those nodes and time to reach those nodes and if the newTime <= maxTime
  and newTime < minTime[nextCity] becoz given to find minTime required to reach lastNode also then we push the 
  cost, nextCity and newTime into queue and update minTime[nextCity] = newTime;.If the city reaches n - 1 we return 
  the fees/cost else we return -1 after the full iteration*/
class Solution{
public:
    int minCost(int maxTime,vector<vector<int>>& edges, vector<int>& passingFees){
        int n = passingFees.size();
        vector<vector<pair<int,int>>>adj(n);
        for(const auto& edge:edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].emplace_back(v,w);
            adj[v].emplace_back(u,w);
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        pq.emplace(passingFees[0],0,0);
        vector<int>minTime(n,INT_MAX);
        minTime[0] = 0;
        while(!pq.empty()){
            auto [cost,time,city] = pq.top();
            pq.pop();
            if(city == n-1)return cost;
            for(const auto& [nextCity,newTime] : adj[city]){
                int newCost = cost + passingFees[nextCity];
                int nextTime = time + newTime;
                if(nextTime <= maxTime && nextTime < minTime[nextCity]){
                    minTime[nextCity] = nextTime;
                    pq.emplace(newCost,nextTime,nextCity);
                }
            }
        }
        return -1;
    }
};
