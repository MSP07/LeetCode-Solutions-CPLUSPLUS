/*approach
  count no of E and decrease them if L comes and update the max in another var and finally return the var*/
class Solution {
public:
    int minimumChairs(string s) {
        int cnt = 0, ans = 0;
        for(char c:s){
            if(c=='E')cnt++;
            else cnt--;
            ans = max(ans,cnt);
        }
        return ans;
    }
};
