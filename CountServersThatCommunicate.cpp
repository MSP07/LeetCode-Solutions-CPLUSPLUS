/*approach
  dfs, counting
  first we count the servers in the rows and cols 
  if there are servers then we count how many servers are present in that row and col
  then either we can call dfs for adj edges and if there is a server we incr the count
  and mark that server as -1 (marking it as visited) and finally return the total servers
  else we can simply iterate again and wherever there is a server if that row or col has
  another server then we have a working server so with this logic also we count the total 
  servers. Optimal approach is the latter approach and so we do it*/
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> rowCount(n,0), colCount(m,0);
        int servers = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (colCount[j]>1 || rowCount[i]>1)){
                    servers++;
                }
            }
        }
        return servers;
    }
};

// const auto init = [](){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();
