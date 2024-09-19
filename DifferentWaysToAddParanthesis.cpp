/*approach
  dp memoization approach
  we simply use recursion dividing the string into two parts one to the left and another to right
  if we encounter any given arithmetic op else we simply add the current string as int to out vector and return
  then we iterate throught the left and right part of the substrings and we push our answers w.r.t chars we encountered
  since this can cause a large runtime ans has overlapping subproblems we use memoization to prevent it*/
class Solution{
    unordered_map<string,vector<int>>memo;
public:
    vector<int> diffWaysToCompute(string expression){
        if(memo.find(expression)!=memo.end()){
            return memo[expression];
        }
        vector<int>ans;

        for(int i=0;i<expression.size();++i){
            char c = expression[i];
            if(c == '+' || c == '-' || c == '*'){
                vector<int>left = diffWaysToCompute(expression.substr(0,i));
                vector<int>right = diffWaysToCompute(expression.substr(i+1));
                for(int l:left){
                    for(int r:right){
                        if(c == '+'){
                            ans.push_back(l+r);
                        }else if(c == '-'){
                            ans.push_back(l-r);
                        }else if(c == '*'){
                            ans.push_back(l*r);
                        }
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(expression));
        }
        memo[expression] = ans;
        return ans;
    }
};
