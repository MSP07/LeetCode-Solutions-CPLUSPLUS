//approach
//two pointers
//we simultaneously add ( or ) in a vector and recursively call the function again
class Solution{
private:
    void solve(int n,int open,int close,vector<string>& ans,string op){
        if(open==0 && close==0){
            ans.push_back(op);
            return;
        }
        if(open==close){
            string op1 = op;
            op1.push_back('(');
            solve(n,open-1,close,ans,op1);
        }else if(open==0){
            string op1 = op;
            op1.push_back(')');
            solve(n,open,close-1,ans,op1);
        }else if(close==0){
            string op1 = op;
            op1.push_back('(');
            solve(n,open-1,close,ans,op1);
        }else{
            string op1 = op;
            string op2 = op;
            op1.push_back('(');
            op2.push_back(')');
            solve(n,open-1,close,ans,op1);
            solve(n,open,close-1,ans,op2);
        }
    }
public:
    vector<string> generateParanthesis(int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int open = n;
        int close = n;
        vector<string>ans;
        string op = "";
        solve(n,open,close,ans,op);
        return ans;
    }
};
