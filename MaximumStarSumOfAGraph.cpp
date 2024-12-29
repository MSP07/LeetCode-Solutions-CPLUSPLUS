/*approach
  graph, greedy, priority_queue
  since the objective is to find max star sum for k nodes
  we first form a adj list to find the weight of neighbors for ith node
  then we iterate from 0 to n and for each node we take the weight of
  neighboring nodes. since we need max one we only take nodes with positive weights
  and then we declare priority queue and add those weights to it then we compute 
  the sum of weights of top k neighboring weights and keep track of max one and return it*/
class Solution{
public:
    int maxStarSum(vector<int>& vals,vector<vector<int>>& edges,int k){
        int n = vals.size();
        vector<vector<int>>adj(n);
        for(auto& edge:edges){
            adj[edge[0]].push_back(vals[edge[1]]);
            adj[edge[1]].push_back(vals[edge[0]]);
        }
        int maxSum = INT_MIN;
        for(int i=0;i<n;i++){
            priority_queue<int>maxHeap;
            for(int neighbor:adj[i]){
                if(neighbor>0){
                    maxHeap.push(neighbor);
                }
            }
            int currSum = vals[i];
            int edges=0;
            while(!maxHeap.empty() && edges<k){
                currSum += maxHeap.top();
                maxHeap.pop();
                ++edges;
            }
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};
