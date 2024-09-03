/*approach
  hash map approach
  we simply hash the given data and iterate with that*/
class Solution{
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<int,int>opHelper;
        for(int i=0;i<nums.size();++i){
            opHelper[nums[i]] = i;
        }
        for(int i=0;i<operations.size();++i){
            nums[opHelper[operations[i][0]]] = operations[i][1];
            opHelper[operations[i][1]] = opHelper[operations[i][0]];
        }
        return nums;
    }
};
