/*approach
  stack
  we push all chars before ) and find the op given
  accordingly we calculate the final result whether t or f*/
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(char c:expression){
            if(c == ')'){
                vector<char>expr;
                while(st.top()!='('){
                    expr.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                char result = 't';
                if(op=='!'){
                    result = (expr[0]=='t') ? 'f' : 't';
                }else if(op=='&'){
                    result = 't';
                    for(char e:expr){
                        if(e=='f'){
                            result = 'f';
                            break;
                        }
                    }
                }else if(op=='|'){
                    result = 'f';
                    for(char e:expr){
                        if(e=='t'){
                            result = 't';
                            break;
                        }
                    }
                }
                st.push(result);
            }else if(c != ','){
                st.push(c);
            }
        }
        return st.top() == 't';
    }
};
