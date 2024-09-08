/*approach
  we iterate thorugh the given string and if there is a '(' we incr the count
  and if there is a ')' we decr the count and we return max of that cnt throughout the iteration of the string*/
class Solution{
public:
    int maxDepth(string s){
        int cnt = 0, ans = 0;
        for(char c:s){
            if(c=='(')cnt++;
            else if(c==')')cnt--;
            ans = max(ans,cnt);
        }
        return ans;
    }
};
