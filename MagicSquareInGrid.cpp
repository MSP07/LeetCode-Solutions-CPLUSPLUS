/*approach
  greedy
  we iterate from 0 to n-3 and m-3 as
  we only need 3x3 matrices then we check whether the chosen
  matrix is a magic one by taking rowSum, colSum and diagSum
  if anytime it is not equal it is false and if we encounter the same 
  element again we return false as in magic square we need diif elements
  if the bool is true we increase count and finally return the ans*/
class Solution{
private:
    bool isMagicSquare(vector<vector<int>>& grid,int row,int col){
        vector<int>count(10,0);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int val = grid[row+i][col+j];
                if(val<1 || val>9 || count[val]>0)return false;
                count[val]=1;
            }
        }

        int sum1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        int sum2 = grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2];
        int sum3 = grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2];
        
        if (sum1 != sum2 || sum2 != sum3) return false;

        int colSum1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
        int colSum2 = grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1];
        int colSum3 = grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2];

        if(colSum1 != colSum2 || colSum2 != colSum3)return false;

        int diag1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diag2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
        
        return sum1 == colSum1 && diag1 == diag2 && diag1 == sum1;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(isMagicSquare(grid,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
