/*approach
  string, greedy
  base cases n=1 return "1", n=2 return "11"
  then start with empty string and we incr cnt till the next ele is equal to curr
  then add that to res string first and then add the reamining "1"'s from ans
  then finally return the res(curr here)*/
class Solution{
public:
    string countAndSay(int n){
        string ans = "1";
        int i=1;
        while(i<n){
            string curr = "";
            for(int j=0;j<ans.size();++j){
                int cnt = 1;
                while(j+1<ans.size() && ans[j]==ans[j+1]){
                    cnt++;
                    j++;
                }
                curr += to_string(cnt) + ans[j];
            }
            ans = curr;
            i++;
        }
        return ans;
    }
};
