/*approach
  we make use of longest palindromic subsequence
  as the min no of insertions will be the non palindromic 
  subsequence length. If there is a palindromic subsequence
  then we dont need to disturb it and the remaining is the 
  length we need to add as min insertions*/
class Solution{
public:
    int minInsertions(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = s.size();
        string r = s;
        reverse(r.begin(),r.end());
        vector<int>curr(n+1,0);
        vector<int>prev(n+1,0);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(s[i-1]==r[j-1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
        }
        return n - curr[n];
    }
};
