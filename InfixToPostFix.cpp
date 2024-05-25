//this is not a part of leetcode but a part of geeksforgeeks
class Solution{
private:
    int precedence(char op){
        if(op=='+' || op=='-')return 1;
        if(op=='*' || op=='/')return 2;
        if(op=='^')return 3;
    }
public:
    string infixToPostfix(string s){
        stack<char>st;
        string result;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(isalum(c)) result += c;
            else if(c=='(')st.push('(');
            else if(c==')'){
                while(!st.empty() && st.top()!='('){
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && precedence(st.top())>=precedence(c)){
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};
