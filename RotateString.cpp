/*approach
  string
  starting from first index in s we check for a substr from x,n-x that matches
  with the goal string from 0,n-x if we find we break there and return true else
  incr x till we find one after this loop if both substrings match we return true else return false*/
class Solution{
public:
    bool rotateString(string s,string goal){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = s.size();
        if(n!=goal.size())return false;
        int x=0;
        while(x<0){
            if(s.substr(x,n-x)==goal.substr(0,n-x)){
                break;
            }else{
                ++x;
            }
        }
        if(s.substr(0,x)==goal.substr(n-x,x))return true;
        else return false;
    }
};
