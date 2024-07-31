/*appraoch
  dp - tabulation approach
  we keep track of max_height and total_thickness we encountered so far
  when the total_thickness exceeds shelfWidth we break
  else we take the max_height we encountered so far and store the min value
  of either adding the cuurent books to shelf or the previous books to shelf
  whichever is minimum and finally return the last stored value.
  base case will be at 0th index we have 0 books and 0 shelves*/
class Solution{
public:
    int minHeightShelves(vector<vector<int>>& books,int shelfWidth){
        int n = books.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;++i){
            int total_thickness = 0;
            int max_height = 0;
            for(int j=i-1;j>=0;j--){
                total_thickness += books[j][0];
                if(total_thickness > shelfWidth){
                    break;
                }
                max_height = max(max_height,books[j][1]);
                dp[i] = min(dp[i],dp[j]+max_height);
            }
        }
        return dp[n];
    }
};
