/*approach
  math, geometry
  to find the line is straight we use the formula that 
  their slope must be same and to exclude division by 0 possibility
  we multiply and check equality if the slope is not equal we return false
  at any point else at last we return true*/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];
        for(int i=2;i<coordinates.size();i++){
            int x = coordinates[i][0], y = coordinates[i][1];
            if((y1-y0)*(x-x1)!=(y-y1)*(x1-x0))return false;
        }
        return true;
    }
};
