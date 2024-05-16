class Solution{
public:
  void sortColors(vector<int<=>&nums){
    int low = 0 , high = nums.size()-1, mid=0;
    while(mid<=high){
      case 0:
        swap(nums[low++],swap[mid++]);
        break;
      case 1:
        mid++;
      case 2:
        swap(nums[mid],nums[high--]);
        break;
    }
  }  
};
