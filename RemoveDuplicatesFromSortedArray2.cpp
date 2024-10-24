/*approach
  two pointers
  the goal is to replace duplicates and return the min len 
  if created a new array after removing duplicates to achieve
  this without using extra space we start from first index with two pointers
  i,j i moves till 2 and from there we chech whether the element at j is repeating
  that is nums[j] == nums[i-2] if so then it is occuring more than 2 times so we skip
  else we replace nums[i] with nums[j] and move i and finally return i*/
class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int i = 0;
        for(int j=0;j<nums.size();++j){
            if(i<2 || nums[j]!=nums[i-2]){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
