/*approach
  we make use of stack
  first we take/reverse the chars that are inside ( )
  now after reversing them we again add them to the stack
  since we have still more reversals to do. 
  then finally when we take the string from stack it will be
  in reversed order due to LIFO nature of stack and hence
  we reverse the string and return it*/
class Solution{
public:
    string reverseParanthesis(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        stack<int>st;
        for(char c:s){
            if(c==')'){
                string temp;
                while(!st.empty() && st.top()!='('){
                    temp += st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                for(char t:temp){
                    st.push(t);
                }
            }else{
                st.push(c);
            }
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
