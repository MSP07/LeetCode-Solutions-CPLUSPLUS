/*appraoch
  dp - approach
  we use the concept of longest increasing subsequence 
  instead of checking for greater property we check 
  whether the current and prev strings have diff of 1 in length
  and whether those strings are in given condition to be counted
  for increasing answer*/
class Solution{
private:
    bool checkPoss(string &s1,string &s2){
        if(s1.size() != 1 + s2.size())return false;
        int i = 0, j = 0;
        while(i < s1.size()){
            if(j < s2.size() && s1[i]==s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return (i==s1.size() && j==s2.size());
    }
public:
    int longestStrChain(vector<string>& words){
        int n = words.size();
        int maxi = 1;
        sort(words.begin(),words.end(),[](const string &a,const string &b){
            return a.length() < b.length();
        });
        vector<int>dp(n,1);
        for(int ind=0;ind<n;++ind){
            for(int prev=0;prev<ind;++prev){
                if(checkPoss(words[ind],words[prev]) && dp[prev] + 1 > dp[ind]){
                    dp[ind] = 1 + dp[prev];
                }
            }
            maxi = max(maxi,dp[ind]);
        }
        return maxi;
    }
};
