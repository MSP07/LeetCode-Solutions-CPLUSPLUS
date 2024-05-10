class Solution {
private:
    bool dfs(int node,int parent,vector<int>&color,vector<vector<int>>&graph){
        if(parent==-1 || color[parent]==2)color[node]=1;
        else color[node]=2;
        for(auto it:graph[node]){
            if(color[it]==-1){
                if(dfs(it,node,color,graph)==false)return false;
            }else if(color[it]==color[node])return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1 && dfs(i,-1,color,graph)==false)return false;
        }
        return true;
    }
};
