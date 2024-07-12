/*approach
  we can write a recursion where we start from end and iterate till first
  if we encounter same chars then we either move both pointers before or 
  only move the first pointer before and add their val both else we simply
  return the val of [i-1][j].
  after tabulating this we can observe use of [i-1] so we space optimise and
  only keep prev array and update it with above logic and finally return prev[m]*/
class Solution{
public:
    int numDistinct(string s,string t){
        int n = s.size();
        int m = t.size();
        vector<double> prev(m+1,0);
        prev[0] = 1;
        for(int i=1;i<=n;++i){
            for(int j=m;j>=1;--j){
                if(s[i-1]==t[j-1]){
                    prev[j] = prev[j-1] + prev[j];
                }else{
                    prev[j] = prev[j];
                }
            }
        }
        return (int)prev[m];
    }
};
