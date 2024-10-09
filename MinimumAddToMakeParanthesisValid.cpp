/*approach
  stack,string
  our aim is to find pair of () while iterating. so if we encounter '(' we push it 
  else we check whether is there any '(' that can form pair with ')' and if it does so
  we pop the preceding '(' else if no preceding '(' is there that can form pair with current ')'
  we simply push the current char(')') also. After iterating the whole array we simply return the
  leftover chars indicating removing them will make the paranthesis balanced.
  logical approach
  In the logical approach we simply take count of open paranthesis and if we enounter closed we check 
  whether pairs can be formed, if not we incr closed paranthesis and finally return the no of open
  and closed that does not form a pair*/
class Solution{
public:
    int minAddToMakeValid(string s){
        if(s.size()==1)return 1;
        //stack approach
        stack<char>st;
        for(char c:s){
            if(c=='('){
                st.push(c);
            }else if(!st.empty() && st.top() == '(' && c==')'){
                st.pop();
            }else{
                st.push(c);
            }
        }
        return st.size();
        //string approach
        string ans = " ";
        for(char c:s){
            if(c=='('){
                ans.push_back(c);
            }else if(ans.back()=='(' && c==')'){
                ans.pop_back();
            }else{
                ans.push_back(c);
            }
        }
        return ans.size();
        //logical approach
        int open = 0;
        int closed = 0;
        for(char c:s){
            if(c=='('){
                open++;
            }else{
                open > 0 ? open-- : closed++;
            }
        }
        return open + closed;
    }
};
