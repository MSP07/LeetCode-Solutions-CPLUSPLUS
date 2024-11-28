/*appraoch
  bfs, priority queue
  we use a version of modified version of djikstra algorithm 
  we start on 0,0 co-ordinates and we iterate through the matrix in diff directions rule 
  out the edge cases and keep on adding the obstacles in the way and update the obstacles that
  we have encountered so far to the min one using priority queue and a vector or a seen array
  then when we reach the corner we return the obstacles rather the min obstacles that we have 
  encountered to reach there as the ans*/
class Solution{
public:
    int minimumObstacle(vector<vector<int>>& grid){
        int n = grid.size(), m=grid[0].size();
        vector<int>dirs = {0,1,0,-1,0};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto[obstacles,cell] = pq.top();
            pq.pop();
            int i = cell.first, j=cell.second;
            if(i==n-1 && j==m-1)return obstacles;
            for(int k=0;k<4;k++){
                int ni=i+dirs[k],nj=j+dirs[k+1];
                if(ni<0 || nj<0 || ni>=n || nj>=m)continue;
                int newObstacles = obstacles + grid[ni][nj];
                if(newObstacles<dist[ni][nj]){
                    dist[ni][nj] = newObstacles;
                    pq.push({newObstacles,{ni,nj}});
                }
            }
        }
        return -1;
    }
};
