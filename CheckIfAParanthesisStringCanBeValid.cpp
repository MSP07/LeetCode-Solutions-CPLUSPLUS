/*approach
  string, counting, greedy
  to find the string is valid the no of open and closed brackets should match
  if string is odd length then it is not possible. Additionally if locked[i]=='1'
  then we can't change the char so we take the count as it is while iterating
  we iterate from left to right taking open bracket counts if the locked[i]=='1'
  then open++ for'(' else open-- if locked[i]=='0' then we can change the brackets to
  our wish so we take the count as per our wish and incr the open count. Then we iterate
  from right to left this time we follow the same but with closed brackets and at any time
  while these iterations if either of the count is < 0 then we return false else finally
  we return true*/
class Solution{
public:
    bool canBeValid(string s,string locked){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = s.size();
        if(n%2)return false;
        int open_cnt = 0;
        for(int i=0;i<n;i++){
            if(locked[i]=='1'){
                if(s[i]=='('){
                    open_cnt++;
                }else{
                    open_cnt--;
                }
            }else{
                open_cnt++;
            }
            if(open_cnt<0)return false;
        }
        int closed_cnt = 0;
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='1'){
                if(s[i]==')'){
                    closed_cnt++;
                }else{
                    closed_cnt--;
                }
            }else{
                closed_cnt++;
            }
            if(closed_cnt<0)return false;
        }
        return true;
    }
};
