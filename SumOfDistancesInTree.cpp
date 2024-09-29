/*approach
  dfs approach
  first we calculate the adj vector
  then we iterate through the adj vector calculating count of the node and its neighboring nodes
  we calculate the result vector with the help of this count vector where result[node] = result[neighbor] + count[neighbor]
  then we iterate through the adj vector again and this time we calculte/manipulate the distances for neighboring nodes and
  finally return the manipulated result vector*/
class Solution{
private:
    void dfs1(int node,int parent,vector<vector<int>>& tree,vector<int>& count,vector<int>& result){
        for(int neighbor:tree[node]){
            if(neighbor != parent){
                dfs1(neighbor,node,tree,count,result);
                count[node] += count[neighbor];
                result[node] += result[neighbor] + count[neighbor];
            }
        }
    }
    void dfs2(int node,int parent,vector<vector<int>>& tree,vector<int>& count,vector<int>& result,int n){
        for(int neighbor:tree[node]){
            if(neighbor != parent){
                result[neighbor] = result[node] - count[neighbor] + (n-count[neighbor]);
                dfs2(neighbor,node,tree,count,result,n);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n,vector<vector<int>>& edges){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>count(n,1);
        vector<int>result(n,0);
        vector<vector<int>>tree;
        for(auto& edge:edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        dfs1(0,-1,tree,count,result);
        dfs2(0,-1,tree,count,result,n);
        return result;
    }
};
