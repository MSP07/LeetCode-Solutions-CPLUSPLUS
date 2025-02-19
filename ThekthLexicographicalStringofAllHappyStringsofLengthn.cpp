/*approach
  backtracking, string
  first we start off with 'a','b','c' and till we reach n
  we check whether the last char added is one of these if not we add one of these char
  and again with that new string we do the whole process again till we reach at n and when we 
  reach n only if k is 0 (we reduce k for each time we reach n) then we return the string as the answer
  finally if there is a string then we have answer else we return ""*/
class Solution{
private:
    void backtrack(int n,string current,vector<string>& happyStrings,int& k){
        if(current.size()==n){
            k--;
            if(k==0){
                happyStrings.push_back(current);
            }
            return;
        }
        for(char ch:{'a','b','c'}){
            if(current.empty() || current.back() != ch){
                current.push_back(ch);
                backtrack(n,current,happyStrings,k);
                current.pop_back();
                if(k==0)return;
            }
        }
    }
public: 
    string getHappyString(int n,int k){
        vector<string>happyStrings;
        string current;
        backtrack(n,current,happyStrings,k);
        return happyStrings.empty() ? "" : happyStrings[0];
    }
};
