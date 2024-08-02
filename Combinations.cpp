/*approach
  backtracking
  we start with with 1 and add it to a ds
  then we recursively call the fn immediately for i+1
  and when it returns we pop_back the last element so as to try
  diff combinations. if the ds.size()==k then we push ds into and and return*/
class Solution{
private:
    void fn(int ind,int n,int k,vector<vector<int>>& ans,vector<int>& ds){
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<=n;++i){
            ds.push_back(i);
            fn(i+1,n,k,ans,ds);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n,int k){
        vector<int>ds;
        vector<vector<int>>ans;
        fn(1,n,k,ans,ds);
        return ans;
    }
};
