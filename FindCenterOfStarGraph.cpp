/*approach
  if the node is center then it should be present in all nodes 
  so we check for the common node in the first 2 elements of edges
  and return it*/
class Solution{
public:
    int findCenter(vector<vector<int>>& edges){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(edges[0][0]==edges[1][1])return edges[0][0];
        else if(edges[0][0]==edges[1][0])return edges[1][0];
        else if(edges[0][1]==edges[1][0])return edges[0][1];
        else return edges[1][1];
    }
};
