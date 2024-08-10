/*aproach
  dp approach
  we iterate from last and check whether both match
  if they match we keep moving till exhaustion else
  we check for '*','.'and prev matches. since in fn we go
  from last to first while tabulating we go from 1 to n
  and we optimise the space as it takes use of prev and curr*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;
        for (int j = 1; j <= m; ++j) {
            if (p[j-1] == '*') {
                prev[j] = prev[j-2];
            }
        }
        for (int i = 1; i <= n; ++i) {
            curr[0] = false;
            for (int j = 1; j <= m; ++j) {
                if (p[j-1] == s[i-1] || p[j-1] == '.') {
                    curr[j] = prev[j-1];
                } else if (p[j-1] == '*') {
                    curr[j] = curr[j-2];
                    if (p[j-2] == s[i-1] || p[j-2] == '.') {
                        curr[j] = curr[j] || prev[j];
                    }
                } else {
                    curr[j] = false;
                }
            }
            prev = curr; 
        }
        return prev[m];
    }
};
