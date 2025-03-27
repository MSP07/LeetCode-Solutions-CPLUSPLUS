/*approach
  sorting
  the given condition only satisfies if all the elements in the
  matrix are of same parity so we first flatten the given 2x2 to 1x1 vector
  and then check whethere there exists a diff parity if so we return -1 immediately
  now we sort the 1d vector to find median which is the centre element and in the 1d vector
  we traverse the abs diff btn num and median / x is the no of steps needed so we calculate that
  sum that up and finally return it*/
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>flat;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                flat.push_back(grid[i][j]);
            }
        }
        int rem = flat[0]%x;
        for(int num:flat){
            if(num%x != rem)return -1;
        }
        int ans = 0;
        sort(flat.begin(),flat.end());
        int median = flat[flat.size()/2];
        for(int num:flat){
            ans += (abs(num-median)/x);
        }
        return ans;
    }
};
