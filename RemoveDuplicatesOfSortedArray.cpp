//approach
//initialise a variable to 1
//if two consecutive elements in the given array are not equal then they are unqiue elements so we update the array with nums[initialised var] = nums[i]
//then we return the var
//edge case is when given array contains only one element we return the size of the array
class Solution{
public:
    int removeDuplicates(vector<int>&nums){
        if(nums.size()<=1)return nums.size();
        int j = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
