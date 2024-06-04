//approach
//we keep a sum var to track the target 
//when becomes target and the required size is reached we return
//we iterate through the range from index to 9 and add different combos till k is met and sum becomes target
class Solution{
private:
    void findCombo(int index,int target,int k,int&sum,vector<vector<int>>& ans,vector<int>& ds){
        if(ds.size()==k && sum==target){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<=9;i++){
            ds.push_back(i);
            sum += i;
            findCombo(i+1,target,k,sum,ans,ds);
            ds.pop_back();
            sum -= i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k,int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int sum = 0;
        vector<vector<int>>ans;
        vector<int>ds;
        findCombo(1,n,k,sum,ans,ds);
        return ans;
    }
};
