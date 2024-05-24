//approach
//intialise two pointers
//iterate through array
//when a non zero entity is detected swap then increase the other pointer

class Solution{
public:
    void moveZeroes(vector<int>&nums){
        int i = 0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[j],nums[i]);
                i++;
            }
        }
    }
};
