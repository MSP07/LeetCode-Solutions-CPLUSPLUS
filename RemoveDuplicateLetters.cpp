/*approach
  stack, greedy
  iterate thorugh the string and mark the last occurences of all the chars then
  again we iterate the chars and push them into stack while checking for lexographical order
  if prev char is higher than curr char order and at the same time the prev char exists somewhere
  in the upcoming indices then we pop the prev char and make it false so that we can take the same
  char later in the string and make it a lexographical order then finally make the chars to a string
  return it and return*/
class Solution{
public:
    string removeDuplicateLetters(string s){
        int n = s.size();
        if(n==1)return s;
        unordered_map<char,int>lastOccur;
        for(int i=0;i<n;++i){
            lastOccur[s[i]] = i;
        }
        stack<char>st;
        vector<bool>in_st(256,0);
        for(int i=0;i<n;++i){
            char c = s[i];
            if(in_st[c])continue;
            while(!st.empty() && st.top()>c && lastOccur[st.top()]>i){
                in_st[st.top()] = false;
                st.pop();
            }
            st.push(c);
            in_st[c] = true;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
