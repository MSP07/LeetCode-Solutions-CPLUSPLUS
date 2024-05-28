//approach
//basic binary search since it is a sorted array
//learned something new , using ios_base::sync_with_stdio(0) and cin.tie(0) will signifiacntly optimise the runtime.
class Solution{
public:
    int search(vector<int>& nums,int target){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<target)low = mid+1;
            else high = mid - 1;
        }
        return -1;
    }
};
