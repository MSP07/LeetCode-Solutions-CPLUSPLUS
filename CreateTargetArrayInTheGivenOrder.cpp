/*approach
  simulation
  we insert the nums[index[i]] at the index i to prevent replacing 
  the element in that index we use the insert function*/
class Solution{
public:
    vector<int> createTargetArray(vector<int>& nums,vector<int>& index){
        vector<int>ans;
        for(int i=0;i<index.size();i++){
            ans.insert(ans.begin()+index[i],nums[i]);
        }
        return ans;
    }
};
