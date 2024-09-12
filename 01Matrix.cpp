/*approach
  bfs approach
  we initialise all values to INT_MAX if we find 0 at a index in org matrix we push that into q
  from that index we update surrounding cells values their distances from the 0 cell by chooosing
  the smaller val in the path and we finally return our ans matrix*/
class Solution{
    vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=9;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(auto& dir:dirs){
                int newX = x + dir[0];
                int newY = y + dir[1];
                if(newX>=0 && newY>=0 && newX<n && newY<m){
                    if(ans[newX][newY] > ans[x][y] + 1){
                        ans[newX][newY] = ans[x][y] + 1;
                        q.push({newX,newY});
                    }
                }
            }
        }
        return ans;
    }
};
