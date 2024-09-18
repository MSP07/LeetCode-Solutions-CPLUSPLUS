/*approach
  stack approach
  we push the indices of string s then if the char is '(' we push it
  else we pop after popping if the st is empty then we push the current index
  else we calculate the maxWays by i-st.top() or maxWays whichever is maximum
  and finally return that maxWays*/
class Solution{
public:
    int longestValidParanthesis(string s){
        int ways = 0;
        if(s.size()==0)return ways;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    ways = max(ways,i-st.top());
                }
            }
        }
        return ways;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
