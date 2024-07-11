/*approach
  we make use of LCA
  we find lca and from that tabule
  we iterate from last and if the char match we add them to ans
  if not we backtrack on which is max and add the omitted char (while iterating)
  to the ans and finally after adding the edge case char we reverse the ans string and return it*/
class Solution{
public:
    string shortest(string str1,string str2){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i = n;
        int j = m;
        string ans = "";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans += str1[i-1];
                i--, j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }else{
                ans += str1[j-1];
                j--;
            }
        }
        while(i>0){
            ans += str1[i-1];
            i--;
        }   
        while(j>0){
            ans += str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
