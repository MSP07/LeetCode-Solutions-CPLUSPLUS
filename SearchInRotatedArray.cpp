class Solution{
public:
    int search(vector<int>& nums,int target){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        //simple traversal
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)return i;
        }
        return -1;
        //using binary search
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target)return mid;
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }else if(nums[mid]<=nums[high]){
                if(nums[mid]<=target && target<=nums[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
