/*approach
  two pointers
  instead of squaring each element sorting and returning
  we can use two pointers to compare the abs greater element
  square it add it to last index and move from last and if we encounter same val with diff indices
  we add the swaured nums twice else we add it once and finally return the new array*/

not so optimal
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size()==1)return {nums[0]*nums[0]};
        int l = 0, r = nums.size()-1;
        vector<int>ans;
        while(l<=r){
            if(abs(nums[l])>abs(nums[r])){
                ans.push_back(nums[l]*nums[l]);
                l++;
            }else if(abs(nums[l])<abs(nums[r])){
                ans.push_back(nums[r]*nums[r]);
                r--;
            }else if(abs(nums[l])==abs(nums[r])){
                if(l!=r){    
                    ans.push_back(nums[l]*nums[l]);
                    ans.push_back(nums[l]*nums[l]);
                }else{
                    ans.push_back(nums[l]*nums[l]);
                }
                l++;
                r--;
            }
        }
        reverse(ans.begin(),ans.end());
        // ans.erase(ans.begin());
        return ans;
    }
};

optimal
if(nums.size()==1)return {nums[0]*nums[0]};
        int l = 0, r = nums.size()-1;
        int i = nums.size()-1;
        vector<int>ans(nums.size());
        while(l<=r){
            if(abs(nums[l])>abs(nums[r])){
                ans[i--] = nums[l]*nums[l];
                l++;
            }else{
                ans[i--] = nums[r]*nums[r];
                r--;
            }
        }
        return ans;
