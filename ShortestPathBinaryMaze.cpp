//approach
//we keep a visited array and increase steps for each direcion we iterate through the direction array 
//we use queue(bfs) for the following problem
//when we reach the destination we return steps+1
class Solution{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>&grid){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        pair<int,int>dest={n-1,m-1};
        vector<vector<int>>dirs={{-1,0},{1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        int steps = 0;
        while(!q.empty()){
            for(int i=0;i<q.size();i++){
                auto node = q.front();
                q.pop();
                if(node==dest)return steps+1;
                for(auto&dir:dirs){
                    int x = node.first + dir[0];
                    int y = node.second + dir[1];
                    if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==0 && !visited[x][y]){
                        visited[x][y] = 1;
                        q.push({x,y});
                    }
                }
                steps++;
            }
        }
        return -1;
    }
};
