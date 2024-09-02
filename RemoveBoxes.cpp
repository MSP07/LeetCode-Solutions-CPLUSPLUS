/*approach
  dp approach
  this is more like partition dp
  we first go till equal elements and we calculate value there that will be (k+1)*(k+1)
  and with that we calc val from next index too then we from next index till last we 
  run a loop to find the max val it is either the curr calc value or from i+1 to m-1 + m to j
  and we return it, to save time and since this has overlapping subproblems we memoize it*/
class Solution{
private:
    int solve(int l,int r,vector<int>& boxes,int k,int dp[101][101][101]){
        if(l>r)return 0;
        int k_here = k;
        int l_here = l;
        if(dp[l][r][k_here]>=0)return dp[l][r][k];
        while(l+1<=r && boxes[l]==boxes[l+1]){
            l++;
            k++;
        }
        int ans = (k+1)*(k+1) + solve(l+1,r,boxes,0,dp);
        for(int m=l+1;m<=r;++m){
            if(boxes[l]==boxes[m]){
                ans = max(ans,solve(l+1,m-1,boxes,0,dp)+solve(m,r,boxes,k+1,dp));
            }
        }
        return dp[l_here][r][k_here] = ans;
    }
public:
    int removeBoxes(vector<int>& boxes){
        int dp[101][101][101];
        memset(dp,-1,sizeof(dp));
        int n = boxes.size();
        if(n==1)return 1;
        return solve(0,n-1,boxes,0,dp);
    }
};
