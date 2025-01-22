/*approach
  bfs, matrix, backtracking
  since the goal is to find highest land from water
  we start by declaring and initating the constant that is water
  then we push the indices of the water cell into queue. Now from this
  position whichever land is near in adj four direction we update that distance
  and push their indices as new starting point. This works because the water cell is 0
  and so the immediate neighboring cells will be 0+1 which will be 1 but after that if the 
  indices remain same then for other cells also the distance will be 0+1 which will be 1 so to
  prevent that since the new updated distance will be +1+1+1..... so on we push their indices
  as new indices in the queue*/
class Solution {
    vector<vector<int>>dirs = {{-1,0},{1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>height(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(auto& dir:dirs){
                int x = dir[0]+i, y=dir[1]+j;
                if(x>=0 && x<n && y>=0 && y<m && height[x][y]==-1){
                    height[x][y] = height[i][j]+1;
                    q.push({x,y});
                }
            }
        }
        return height;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
