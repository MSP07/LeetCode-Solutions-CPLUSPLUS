/*approach
  dfs,dp approach
  we run a dfs function if we come across a out of boundary we return 1 indicating we found a path
  if max  Move becomes 0 we return 0 else we calculate for up left right down and return it with
  %mod and memoize it for overlapping subproblems*/
class Solution{
    const int mod = 1e9 + 7;
    int memo[51][51][51];
private:
    int dfs(int n,int m,int maxMove,int startRow,int startColumn){
        if (startRow < 0 || startColumn < 0 || startRow >= m || startColumn >= n) return 1;
        if (maxMove == 0) return 0;
        if (memo[startRow][startColumn][maxMove] != -1) return memo[startRow][startColumn][maxMove];
        int up = dfs(m, n, maxMove - 1, startRow - 1, startColumn);
        int down = dfs(m, n, maxMove - 1, startRow + 1, startColumn);
        int left = dfs(m, n, maxMove - 1, startRow, startColumn - 1);
        int right = dfs(m, n, maxMove - 1, startRow, startColumn + 1);
        return memo[startRow][startColumn][maxMove] = ((up + down) % mod + (left + right) % mod) % mod;
    }
public:
    int findPaths(int m,int n,int maxMove,int startRow,int startColumn){
        memset(memo,-1,sizeof(memo));
        return dfs(n,m,maxMove,startRow,startColumn);
    }
};
