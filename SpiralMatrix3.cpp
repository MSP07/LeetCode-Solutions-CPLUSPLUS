/*approach
  we simply iterate through the matrix
  with the given conditions check for boundary case
  and add them to ans and finally return it*/
class Solution{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        int x = rStart, y = cStart;
        int steps = 1, dir = 0;
        ans.push_back({x,y});
        while(ans.size() < rows * cols){
            for(int i=0;i<2;++i){
                for(int j=0;j<steps;++j){
                    x += directions[dir][0];
                    y += directions[dir][1];
                    if(x>=0 && x<rows && y>=0 && y<cols){
                        ans.push_back({x,y});
                    }
                }
                dir = (dir+1)%4;
            }
            ++steps;
        }
        return ans;
    }
};
