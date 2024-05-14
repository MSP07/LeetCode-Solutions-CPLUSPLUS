class Solution{
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>&grid){
            int n = grid.size();
            int m = grid[0].size();
            pair<int,int>dest={n-1,m-1};
            if(grid[0][0]==1 || grid[dest.first][dest.second]==1)return -1;
            queue<pair<int,int>>q;
            q.push({0,0});
            vector<vector<int>>dirs={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,-1},{-1,-1},{1,1}};
            vector<vector<int>>visited(n,vector<int>(m,0));
            int steps = 0;
            while(!q.empty()){
                int size = q.size();
                for(int i=0;i<size;i++){
                    auto node = q.front();
                    q.pop();
                    if(node==dest)return steps+1;
                    for(auto&dir:dirs){
                        int nx = node.first + dir[0];
                        int ny = node.second + dir[1];
                        if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0 && !visited[nx][ny]){
                            visited[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
                steps++;
            }
            return -1;
        }
};
